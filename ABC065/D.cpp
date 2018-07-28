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
#include <limits.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);
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

template <typename T>
struct UnionFind {
	T n;
	vector<T>d;
	UnionFind() {}
	UnionFind(T n) :n(n), d(n, -1) {}
 
	int root(T x) {
		if (d[x] < 0) return x;
		return d[x] = root(d[x]);
	}
	bool unite(T x,T y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (size(x) < size(y)) swap(x, y); 
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	int size(T v) { return -d[root(v)]; }
};

int
main(void){
  ll n;
  cin >> n;
  ll x[n], y[n];
  REP(i, n) cin >> x[i] >> y[i];

  int idx[n][4];
  REP(i, n) {
    idx[i][0] = x[i];
    idx[i][1] = y[i];
    idx[i][2] = i;
    idx[i][3] = 0;
  }

  sort(x, x+n);
  sort(y, y+n);

  cout << x[0] << endl;

  ll m = LLONG_MAX;
  ll ans = 0LL;
  int x_v, y_v, x_v_n, y_v_n;
  ll diff1, diff2;
  
  REP(i, n-1){
    diff1 = x[i+1] - x[i];
    if(m > diff1) {
      m = diff1;
      x_v = x[i];
      y_v = y[i];
      x_v_n = x[i+1];
      y_v_n = y[i+1];       
    }
    diff2 = y[i+1] - y[i];
    if(m > diff2) {
      m = diff2;
      x_v = x[i];
      y_v = y[i];
      x_v_n = x[i+1];
      y_v_n = y[i+1];       
    }    
  }

  int idx_itr = 0, idx_itr_n = 0;
  REP(i, n) {
    if(x_v == idx[i][0] && y_v == idx[i][1]) idx_itr = idx[i][2];
    if(x_v_n == idx[i][0] && y_v_n == idx[i][1]) idx_itr_n = idx[i][2];    
  }

  idx[idx_itr][3] = 1; // visited  
  idx[idx_itr_n][3] = 1;  
  ans += m;

  
  
  return 0;
}
