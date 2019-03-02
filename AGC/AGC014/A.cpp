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

/*
void debug(int v){cout << v << endl;}
*/
void debug(int u,int v, int r){
  cout<<u<<" "<<v<<" "<<r<<endl;
}

//AC
//無限が-1

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  if(a == b && b == c & c == 1) {cout << 0 << endl; return 0;}
  if(a == b && b == c) {cout << -1 << endl; return 0;}
  int ans = 0;
  while(true){
    if(a%2 || b%2 || c%2) break;
    int tmp[3];
    tmp[0] = a/2; tmp[1] = b/2; tmp[2] = c/2;
    a = tmp[1]+tmp[2];
    b = tmp[0]+tmp[2];
    c = tmp[0]+tmp[1];
    //debug(a, b, c);
    ans++;
  }  
  cout << ans << endl;
  
  return 0;
}
