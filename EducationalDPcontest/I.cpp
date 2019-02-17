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

double dp[3010][3010], p[3010];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  REP(i, n) cin >> p[i];

  REP(i, n) REP(j, n) dp[i][j] = 0;
  
  //dp[i][j] := i番目までのコインを使って、表がjの場合の確率
  //REP(i, n) dp[0][i] = 1;
  dp[0][0] = 1;
  REP(i, n){
    //jは0~i番目まで
    REP(j, i+1){
      //i番目が表
      dp[i+1][j+1] += dp[i][j] * p[i];
      //i番目が裏
      dp[i+1][j] += dp[i][j] * (1-p[i]);
    }
  }

  double ans = 0.0;
  FOR(i, n/2+1, n+1) ans += dp[n][i];  
  cout << setprecision(10) << ans << endl;
  
  return 0;
}
