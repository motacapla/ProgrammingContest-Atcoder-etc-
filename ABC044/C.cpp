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

//解説AC
//https://atcoder.jp/contests/abc044/submissions/4119290

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a;
  cin >> n >> a;
  ll dp[51][2501] = {};
  dp[0][0] = 1;
  REP(i, n){
    int x;
    cin >> x;
    ROF(j, 50, 1) ROF(k, 2500-x, 0) dp[j][k+x] += dp[j-1][k]; //まとめて数え上げる
  }
  ll ans = 0LL;
  FOR(i, 1, n+1) ans += dp[i][i*a]; //a, 2a, 3a, ... / i
  cout << ans << endl;
  return 0;
}

/*
int x[575];
int xx[575];

int main(void){
  int n,a,m=0;
  cin >> n >> a;
  REP(i, n) {
    cin >> x[i];
    xx[x[i]]++;
    m = max(m, x[i]);
  }
  ll ans = 0LL;
  int aa = xx[a];
  ans += pow(2, aa) - 1; //2^a - 1
  int l=a-1, r=a+1;
  while(1 <= l && r <= m){
    int ln = xx[l], lr = xx[r];
    ans += ln*lr*(1<<aa);
    l--;
    r++;
  }
  cout << ans << endl;
  return 0;
}
*/
