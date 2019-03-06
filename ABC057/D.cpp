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

/*
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}
*/

// 解説AC
// https://img.atcoder.jp/abc057/editorial.pdf

// nCrよりパスカルの三角形のほうが良い?

// Combination Table
ll C[51][51]; // C[n][k] -> nCk

void comb_table(int N){
  for(int i=0;i<=N;++i){
    for(int j=0;j<=i;++j){
      if(j==0 or j==i){
	C[i][j]=1LL;
      }else{
	C[i][j]=(C[i-1][j-1]+C[i-1][j]);
      }
    }
  }
}

ll v[52];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n, a, b;
  cin >> n >> a >> b;
  REP(i,n) cin >> v[i];
  sort(v, v+n, greater<ll>());
  ll max_v = v[0];
  
  double ave = 0LL;
  REP(i,a) ave += v[i];
  cout << fixed;
  cout << setprecision(20);
  cout << (double)ave/a << endl;

  comb_table(n);

  ll num = 0, pos = 0;
  REP(i,n){
    if(v[i] == v[a-1]){
      num++;
      if(i < a) pos++;
    }
  }

  ll ans = 0LL;
  if(pos == a) for(;pos<b+1;pos++) ans += C[num][pos];  
  else ans += C[num][pos];
  cout << ans << endl;
  return 0;
}
