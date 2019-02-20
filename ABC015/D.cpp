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

const int MAXN = 17000;
int w, n, k;
int a[100], b[100];

// dp[i][j][k] := i番目までの幅j以下でスクリーンショットk枚以下となるような最大重要度
int dp[64][MAXN][64];

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> w >> n >> k;
  REP(i, n) cin >> a[i] >> b[i];

  dp[0][0][0] = 0;
  REP(i, n+1){
    REP(j, w+1){
      REP(l, k+1){
	if(j-a[i] >= 0) dp[i+1][j][l+1] = max(dp[i][j-a[i]][l]+b[i], dp[i][j][l+1]);
	else dp[i+1][j][l] = dp[i][j][l];
      }
    }
  }

  cout << dp[n][w][k] << endl;
    
  return 0;
}
