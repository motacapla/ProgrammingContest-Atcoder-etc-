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
    if(d[y] < d[x]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  int size(T x){ return -d[find(x)];}
  bool same(T x, T y){
    return find(x) == find(y);
  }
};

//解説AC

int n, k, l;
bool visited[1000010];
ll ans[1000010];
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> l;
  UnionFind<int> doro = UnionFind<int>(n+1); //nだとREでるの謎い..
  UnionFind<int> tetu = UnionFind<int>(n+1); //nだとREでるの謎い..

  REP(i, k){
    int p, q;
    cin >> p >> q;
    p--; q--;
    doro.unite(p, q);
  }
  REP(i, l){
    int r, s;
    cin >> r >> s;
    r--; s--;
    tetu.unite(r, s);
  }
  // -- ここから -- //
  P roots[n];
  map<P, int> ans;
  REP(i, n){
    roots[i] = {doro.find(i), tetu.find(i)};
    ans[roots[i]]++;
  }
  REP(i, n) cout << ans[roots[i]] << endl;
  // -- ここまで -- //

  return 0;
}
