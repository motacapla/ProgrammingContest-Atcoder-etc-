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

//解説AC
//1. Vをカウント
//2. 答えは価値が大きい方から見る
//3. 重さの代わりに価値をつめ放題する (最小の重さがつまれるように)
//4. loopの境界n+1まで
//5. 初期化はdp[0][0] = 0, dp[0][i] = INF

ll N, W, V;
ll w[110], v[110];
const ll INF = 1e9;
ll VAL = 1e5+1;
ll dp[110][100010];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> W;
  REP(i, N) {
    cin >> w[i] >> v[i];
    V += v[i];
  }
  VAL = V+1;
  //漸化式ver.
  // dp[i][j] := i番目までの価値jとなる最小重さ
  REP(j, VAL) dp[0][j] = INF;
  dp[0][0] = 0;
  
  REP(i, N+1){
    REP(j, VAL){
      dp[i+1][j] = dp[i][j];
      if(j >= v[i]){
	dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
      }
    }
  }

  ll ans = 0LL;
  ROF(i, V, 0){
    if(dp[N][i] <= W){
      cout << i << endl;
      return 0;
    }
  }
  
  
  return 0;
}
