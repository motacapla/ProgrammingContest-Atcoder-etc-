//$g++ -std=c++11 Template.cpp 

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

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

ll N, W;
ll w[110], v[110];

ll dp[110][100010];

ll dfs(ll i, ll j){
  // >= 0だと遅いので != 初期値とする
  if(dp[i][j] != -1) return dp[i][j];
  ll res;
  if(i == N) res = 0;
  else if(j < w[i]) res = dfs(i+1, j);
  else res = max(dfs(i+1, j), dfs(i+1, j-w[i])+v[i]);
  return dp[i][j] = res;
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> W;
  REP(i, N) cin >> w[i] >> v[i];

  /*
  //漸化式ver.
  // dp[i][j] := i番目までの重さW以下となる最大価値
  dp[0][0] = 0;
  REP(i, N+1){
    REP(j, W+1){
      if(j-w[i] >= 0){
	dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
      }
      else{
	dp[i+1][j] = dp[i][j];
      }
    }
  }
  cout << dp[N][W] << endl;
  */

  memset(dp, -1, sizeof(dp));
  cout << dfs(0, W) << endl;
  
  return 0;
}
