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

int dp[10][10];

int
main(void){  
  int h, w;
  cin >> h >> w;

  REP(i, 10) REP(j, 10) cin >> dp[i][j];

  int a;
  int vec[11] = {};
  REP(i, h*w) {
    cin >> a;
    ++a;
    ++vec[a];
  }

  /*
  REP(i, 11){
    cout << vec[i] << endl;
  }
  */

  REP(k, 10){
    REP(i, 10){
      REP(j, 10){
	dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
      }
    }
  }

  /*
  REP(i, 10) {
    REP(j, 10) {  
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  */

  int ans = 0;
  FOR(i, -1, 10){
    if(i != -1){
      while(vec[i+1]>0){
	ans += dp[i][1];
	vec[i+1]--;
      }
    }
    //cout << i << " " << ans << endl;
  }

  cout << ans << endl;
  
  return 0;
}
