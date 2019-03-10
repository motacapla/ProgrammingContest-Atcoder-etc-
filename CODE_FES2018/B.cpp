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

//解説AC
//https://atcoder.jp/contests/code-festival-2018-final-open/submissions/4479961

ll n, m;
ll r[100010];

const int MAX = 234567;
ll fac[MAX], finv[MAX], inv[MAX];

inline void init() {
	fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = MUL(fac[i - 1], i);
		inv[i] = MOD - MUL(inv[MOD % i], MOD / i);
		finv[i] = MUL(finv[i - 1], inv[i]);
	}
}
inline ll comb(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return MUL(fac[n], MUL(finv[k], finv[n - k]));
}


int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  vector<double> v(n+1, 0);
  FOR(i, 1, n+1) v[i] = log(i) + v[i-1];
  
  double p = v[n] - log(m) * n;
  REP(i, m){
    int t; cin >> t;
    p -= v[t];
  }

  p /= -log(10);
  cout << (int) p+1 << endl;
  
  return 0;
}
