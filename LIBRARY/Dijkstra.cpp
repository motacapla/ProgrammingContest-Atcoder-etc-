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
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);
#define REVERSE(v) reverse((v).begin(), (v).end())

struct edge {
    int from, to, cost;
    edge(int to, int cost): to(to), cost(cost) {}
};

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
constexpr double PI  = acos(-1.0);
constexpr int INF = 1000000000 + 1;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

template<class T> inline T sqr(T x) {return x*x;}

// edge ... {cost, to}
//s: start point, g: graph, d: distance
template <typename T = pair<int, int>>
void Dijkstra(int s, vector<edge> g[], vector<int> &d) {
    int num = d.size();
    priority_queue<T, vector<T>, greater<T>> q;
    //初期化
    REP(i, num) d[i] = INF;
    d[s] = 0;
    q.emplace(0,s);
 
    while (!q.empty()) {
        T p = q.top(); q.pop();
        int v = p.second; // vertex
        if (d[v] < p.first) continue;
        for (int i = 0; i < g[v].size(); ++i) {
            edge e = g[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.emplace(d[e.to], e.to);
            }
        }
    }
}

const int MAX_N = 1000000;

//graph
vector<edge> ef[MAX_N], eb[MAX_N];
//dist
vector<int> df[MAX_N], db[MAX_N];

int
main(void){
  ll n, m, t;
  cin >> n >> m >> t;
  ll A[n];
  ll a[m], b[m], c[m];

  
  REP(i, n) cin >> A[i];
  REP(i, m) cin >> a[i] >> b[i] >> c[i];



  REP(i, m){
    ef[a[i]-1].emplace_back(b[i]-1, c[i]);
    eb[b[i]-1].emplace_back(a[i]-1, c[i]);
    //cout << a[i]-1 << " " << b[i]-1 << " " << c[i] << endl;
  }
  
  //round
  Dijkstra(0, ef, df);
  //trip
  Dijkstra(0, eb, db);

  ll ans = 0LL;
  REP(i, n){
    ll cost = df[i] + db[i];
    if(cost <= t) ans = max(ans, (ll)(A[i] * (t - cost)));
  }
  cout << ans << endl;
  
  return 0;
}
