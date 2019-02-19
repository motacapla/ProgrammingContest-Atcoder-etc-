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

//解説AC
//蟻本pp.293
//LCA

const int MAX_V = 100010;
const int MAX_LOG_V = 18;
int n,q;

vector<int> G[MAX_V];
int root;
int parent[MAX_LOG_V][MAX_V], depth[MAX_V];

void dfs(int v, int p, int d){
  parent[0][v] = p;
  depth[v] = d;
  REP(i, G[v].size()){
    if(G[v][i] != p) dfs(G[v][i], v, d+1);
  }
}
void init(int V){
  dfs(root, -1, 0);
  for(int k=0; k+1 < MAX_LOG_V; k++){
    REP(v, V){
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k+1][v] = parent[k][parent[k][v]];
    }
  }
}
int lca(int u, int v){
  if(depth[u] > depth[v]) swap(u,v);
  REP(k, MAX_LOG_V){
    if((depth[v]-depth[u]) >> k & 1) v = parent[k][v];
  }
  if(u == v) return u;
  ROF(k, MAX_LOG_V-1, 0){
    if(parent[k][u] != parent[k][v]){
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int
main(void){

  cin >> n;
  REP(i, n-1){
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);    
  }
  init(n);

  cin >> q;
  REP(i, q){
    int a, b;
    cin >> a >> b;
    a--, b--;
    int p = lca(a, b);
    cout << depth[a]-depth[p]+depth[b]-depth[p]+1 << endl;
  }
  
  return 0;
}


/*
//BEGIN CUT HERE
struct LowestCommonAncestor{
  const int MAX_LOG_V = 50;

  vector<vector<int> > G,parent;
  int root=0,V;
  vector<int> depth;
  LowestCommonAncestor(){}
  LowestCommonAncestor(int V):V(V){init();}
  
  void init(){
    for(int i=0;i<(int)G.size();i++) G[i].clear();
    G.clear();
    for(int i=0;i<(int)parent.size();i++) parent[i].clear();
    parent.clear();
    depth.clear();
    G.resize(V);
    parent.resize(MAX_LOG_V,vector<int>(V));
    depth.resize(V);
  }
  
  void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void dfs(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++){
      if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    }
  }

  void construct(){
    dfs(root,-1,0);
    for(int k=0;k+1<MAX_LOG_V;k++){
      for(int v=0;v<V;v++){
	if(parent[k][v]<0) parent[k+1][v]=-1;
	else parent[k+1][v]=parent[k][parent[k][v]];
      }
    }
  }
  int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAX_LOG_V;k++){
      if((depth[v]-depth[u])>>k&1){
	v=parent[k][v];
      }
    }
    if(u==v) return u;
    for(int k=MAX_LOG_V-1;k>=0;k--){
      if(parent[k][u]!=parent[k][v]){
	u=parent[k][u];
	v=parent[k][v];
      }
    }
    return parent[0][u];
  }
};
//END CUT HERE

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  LowestCommonAncestor lca(n);
  
  REP(i, n-1){
    int x, y;
    cin >> x >> y;
    x--; y--;
    lca.add_edge(x,y);
    lca.add_edge(y,x);        
  }
  
  lca.construct();
  
  int q;
  cin >> q;
  REP(i, q){
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << lca.lca(a, b)+1 << endl;
  }
  
  return 0;
}
*/
