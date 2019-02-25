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

int a[100010];
//dp[i][j]:=i番目の子供にj個のあめを配る場合の数
ll dp[110][100010];
int sum[100010];

//解説AC
//https://atcoder.jp/contests/dp/submissions/4362880

int
main(void){  
  int n, k;
  cin >> n >> k;
  REP(i, n) cin >> a[i];

  FOR(i, 0, a[0]+1) dp[0][i] = 1;
  FOR(i, 1, n){
    dp[i][0] = dp[i-1][0];
    
    FOR(j, 1, a[i]+1){
      dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
    }
    FOR(j, a[i]+1, k+1){
      dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
      dp[i][j] -= (dp[i-1][j-a[i]-1]);
      dp[i][j]%=MOD;
      if(dp[i][j] < 0) dp[i][j] += MOD;
    }
  }
  
  cout << dp[n-1][k] << endl;
  return 0;
}


/*
	rep(i, K + 1)
		s[0][i + 1] = s[0][i] + dp[0][i];
 
	for (int n = 1; n < N; n++){
		for (int k = 0; k <= K; k++){
			dp[n][k] = (s[n - 1][k + 1] - s[n - 1][max(0LL, k - a[n])])%mod;
			s[n][k + 1] = (s[n][k] + dp[n][k])%mod;
 
//			for (int i = 0; i <= a[n]; i++)
//				(dp[n][k] += dp[n - 1][k - i])%=mod;
		}
	}

 */
