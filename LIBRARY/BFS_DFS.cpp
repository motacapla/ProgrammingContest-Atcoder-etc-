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

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

class Graph
{
public:
  int V;
  list<int> *adj;
  bool *visited;
  
  Graph(int V);
  void addEdge(int v, int w);  
  void BFS(int s);
  void DFS(int s);
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
  visited = new bool[V];
  REP(i, V) visited[i] = false;  
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
}

void Graph::BFS(int s){
  queue<int> q;
  q.push(s);
  visited[s] = true;  
  
  while(!q.empty()){
    s = q.front();
    q.pop();
    cout << s << " ";
    
    //iterator型はリストのインデックスを表す. *iで実態を参照できる.
    for(list<int>::iterator i=adj[s].begin(); i!= adj[s].end(); ++i){      
      if(!visited[*i]){
	visited[*i] = true;
	q.push(*i);
      }
    }  
  }
  cout << endl;
}

void Graph::DFS(int s){  
  visited[s] = true;
  cout << s << " ";
  for(list<int>::iterator i=adj[s].begin(); i!= adj[s].end(); ++i){      
    if(!visited[*i]) DFS(*i);
  }
}

int
main(void){

  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "BFS" << endl;
  g.BFS(2);

  REP(i, g.V) g.visited[i] = false;
  
  cout << "DFS" << endl;  
  g.DFS(2);
  
  return 0;
}
