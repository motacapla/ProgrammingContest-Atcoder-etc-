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
#include <stack>
#include <bitset>

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

string table[2010];

ll yoko[2010][2010];
ll tate[2010][2010];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;

  REP(i, h){
    string s;
    cin >> s;
    table[i] = s;
  }

  //REP(i, h) REP(j, w) cout << table[i][j] << endl;

  REP(i, h){
    int start=0, cnt=0;
    REP(j, w){
      if(table[i][j] == '#'){
	FOR(k, start, j) {
	  yoko[i][k] = cnt;
	}
	yoko[i][j] = 0;
	cnt = 0;
	start = j+1;
      }
      else if(j == w-1){
	FOR(k, start, w) {
	  yoko[i][k] = cnt+1;
	}	
      }
      else {
	cnt++;
      }
    }        
  }
  /*
  //check
  REP(i, h){
    REP(j, w) cout << yoko[i][j] << " ";
    cout << endl;
  }
  */

  REP(j, w){
    int start=0, cnt=0;    
    REP(i, h){      
      if(table[i][j] == '#'){
	FOR(k, start, i) {
	  tate[k][j] = cnt;
	}
	tate[i][j] = 0;
	cnt = 0;
	start = i+1;
      }
      else if(i == h-1){
	FOR(k, start, h) {
	  tate[k][j] = cnt+1;
	}	
      }
      else {
	cnt++;
      }
    }        
  }
  /*
  //check
  REP(i, h){
    REP(j, w) cout << tate[i][j] << " ";
    cout << endl;
  }  
  */

  ll ans = 0LL;
  REP(i, h) REP(j, w) ans = max(ans, yoko[i][j]+tate[i][j]);
  cout << ans-1 << endl;
  
  return 0;
}
