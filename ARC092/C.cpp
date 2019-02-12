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

const int MAXV = 1e5;
const int INF = 1e9;
struct edge{ int to, cap, rev; };
vector<edge> G[MAXV];
bool used[MAXV];

// from -> to へ向かう容量capの辺をグラフに追加
void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f){
  if(v == t) return f;
  used[v] = true;
  REP(i, G[v].size()){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap>0){
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
	e.cap -= d;
	G[e.to][e.rev].cap += d;
	return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t){
  int flow = 0;
  while(true){
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if(f==0) return flow;
    flow += f;
  }
}

int a[575], b[575], c[575], d[575];

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  REP(i, n) cin >> a[i] >> b[i];
  REP(i, n) cin >> c[i] >> d[i];

  int s, t;
  s = n*2, t = s+1;
  REP(i, n) add_edge(s, i, 1);
  REP(i, n) add_edge(n+i, t, 1);
  
  REP(i, n){
    REP(j, n){
      if(a[i] < c[j] && b[i] < d[j]) {
	add_edge(i, n+j, 1);	
      }
    }
  }

  cout << max_flow(s, t) << endl;
  
  return 0;
}
