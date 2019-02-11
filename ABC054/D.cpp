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

const int INF = 1e7;
const int num_max = 401;
int dp[41][401][401];
int a[41], b[41], c[41];
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, ma, mb;
  cin >> n >> ma >> mb;
  REP(i, n) cin >> a[i] >> b[i] >> c[i];

  //n+1番目までちゃんと初期化する
  REP(i, n+1) REP(j, num_max) REP(k, num_max) dp[i][j][k] = INF;

  dp[0][0][0] = 0;
  REP(i, n){
    REP(j, num_max){
      REP(k, num_max){
	if(dp[i][j][k] == INF) continue; 
	chmin(dp[i+1][j][k], dp[i][j][k]);
	chmin(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);	
      }
    }
  }

  ll ans = INF;
  //1番目からやる
  FOR(j,1,num_max) FOR(k,1,num_max) if(j*mb==k*ma) ans = min((int)ans, dp[n][j][k]);

  if(ans == INF) ans = -1;
  cout << ans << endl;
  
  return 0;
}

/*
デバッグポイント
- 初期化が全部できてるかチェック
- ループの境界条件チェック
- 漸化式チェック
- 最後の結果集計部分チェック
 */
