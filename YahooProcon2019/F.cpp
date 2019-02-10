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
typedef pair<int, int> P;

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

const int MAX = 210000;
const ll MOD = 998244353;
ll dp[5100][5100];
ll sum[5100];
ll fac[MAX], finv[MAX], inv[MAX];

ll comb_init(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  FOR(i, 2, MAX){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
ll comb(int n, int k){
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}
ll modpow(ll a,ll n, ll mod){
  ll res = 1;
  while(n > 0){
    if(n&1) res = res*a%mod;
    a = a*a%mod;
    n >>= 1;
  }
  return res;
}
ll modinv(ll a, ll mod){
  ll b = mod, u = 1, v = 0;
  while(b){
    ll t = a/b;
    a -= t*b; swap(a, b);
    u -= t*v; swap(u, v);
  }
  u %= mod;
  if(u < 0) u += mod;
  return u;
}
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  comb_init();
  int n = s.size();

  sum[0] = 0LL;
  REP(i, n){
    int num = 0;
    if(s[i] == '0') num += 2;
    else if(s[i] == '1') num += 1;
    sum[i+1] = sum[i] + num;
  }
  //なぜ 1?
  dp[0][0] = 1;
  REP(i, n){
    REP(r, i+1){
      if(dp[i][r] == 0) continue;
      //赤の総数が r+1個 以上ならば, 赤増やす
      if(sum[i+1] >= r+1){
	dp[i+1][r+1] += dp[i][r];
	dp[i+1][r+1] %= MOD;
      }
      //青の総数が i+1-r個 以上ならば, 青増やす
      if((i+1)*2-sum[i+1] >= i+1-r){
	dp[i+1][r] += dp[i][r];
	dp[i+1][r] %= MOD;
      }
    }
  }
  ll res = 0LL;
  //赤の数が0~n個の場合 * comb の総和
  REP(r, n+1){
    res += dp[n][r] * comb(n, sum[n]-r)%MOD;
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
