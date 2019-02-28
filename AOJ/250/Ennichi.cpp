//#include <bits/stdc++.h>
#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iomanip>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define ROF(i, j, k) for(int i = (int)(j); i >= (int)(k); --i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n)
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

int h, w, n;

bool done(char b[31][31]){
  REP(i,h) REP(j,w) if(b[i][j] != '.') return false;
  return true;
}

bool vanish(char b[31][31]){
  bool kesu[31][31] = {};
  REP(i,h) REP(j,w){
    char c=b[i][j];
    if(c == '.') continue;
    //たてに揃えることが可能
    if(i+n <= h){
      bool ok = true;
      REP(k, n) if(b[i+k][j] != c) {ok = false; break;}
      if(ok) REP(k, n) kesu[i+k][j] = true;
    }
    //横に揃えることが可能
    if(j+n <= w){
      bool ok = true;
      REP(k, n) if(b[i][j+k] != c) {ok = false; break;}
      if(ok) REP(k, n) kesu[i][j+k] = true;
    }          
  }
  bool ok=false;
  REP(i,h) REP(j,w) if(kesu[i][j]) b[i][j]='.', ok=true;
  return ok;
}

void fall(char b[31][31]){
  REP(j,w){
    int m=0;
    char s[31];
    ROF(i,h-1,0) if(b[i][j] != '.') s[m++] = b[i][j];
    REP(i,h) b[i][j] = '.';
    //h-1が下、下から埋める
    REP(i,m) b[h-i-1][j] = s[i];
  }
}

bool solve(char t[31][31]){
  char b[31][31];  
  REP(i, h) REP(j, w) b[i][j] = t[i][j];
      
  if(done(b)) return true;
  fall(b);
  if(!vanish(b)) return false;
  fall(b);

  return solve(b);
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  char table[31][31];

  cin >> h >> w >> n;
  REP(i, h) {
    REP(j, w) {
      cin >> table[i][j];
    }
  }
  //REP(i, h) REP(j, w) cout << table[i][j] << " ";
  REP(i,h) REP(j,w-1){
    swap(table[i][j], table[i][j+1]);
    if(solve(table)){ cout << "YES" << endl; return 0;}
    swap(table[i][j], table[i][j+1]);
  }

  cout << "NO" << endl;
  
  return 0;
}
