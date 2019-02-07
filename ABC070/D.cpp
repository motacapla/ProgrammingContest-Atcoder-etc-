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

#define MAX_N 10000001

int n;

struct edge {
  int from, to;
  ll cost;
    edge(int to, ll cost): to(to), cost(cost) {}
};

vector<edge> graph[MAX_N];
ll d[MAX_N];

void bfs(int k){
  queue<int> q;
  q.push(k);
  while(!q.empty()){
    int from = q.front(); q.pop();
    REP(i, graph[from].size()){
      edge e = graph[from][i];
      int to = graph[from][i].to;
      ll cost = graph[from][i].cost;
      if(d[to]!=0) continue;
      d[to] = d[from] + cost;
      q.push(to);
    }
  }
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  REP(i, n-1) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edge e1 = {(int)b, c};
    edge e2 = {(int)a, c};
    graph[a].emplace_back(e1);
    graph[b].emplace_back(e2);
  }

  //wf まにあわない
  int q, k;
  cin >> q >> k;
  k--;

  //kから各頂点へのの最短距離を求める
  bfs(k);
  
  REP(i, q){    
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << d[x] + d[y] << endl;
  }
  
  return 0;
}
