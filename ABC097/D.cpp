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

template <typename T>
class UnionFind {
public:
  T n;
  vector <T> d;
  UnionFind(T n) :d(n, -1) {} 
  int find(T x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(T x, T y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(size(x) < size(y)) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  int size(T v){ return -d[find(v)];}
  bool same(T x, T y){
    return find(x) == find(y);
  }
};

int p[1000000], x[1000000], y[1000000];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  REP(i, n) cin >> p[i];
  REP(i, m) cin >> x[i] >> y[i];

  UnionFind<int> uf = UnionFind<int>(n+1); //nだとREでるの謎い..

  REP(i, m) uf.unite(x[i], y[i]);

  ll ans = 0LL;

  REP(i, n) if(uf.same(i+1, p[i])) ans++; 

  cout << ans << endl;
  
  //if(uf.unite(x[0], y[0])) cout << "success" << endl;
  //cout << uf.size(5) << endl;;
  
  return 0;
}
