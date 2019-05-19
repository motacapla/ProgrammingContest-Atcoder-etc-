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
#include <stack>
#include <bitset>

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

#define MAXN 100010
#define vi vector<int>

vi edges[MAXN];
vi costs[MAXN];
 
int color[MAXN];
int parent[MAXN];

void dfs(int node, int col){
  color[node] = col;
  for(int i= 0; i<edges[node].size(); i++){
    if(edges[node][i] != parent[node]){
      //接続先の親を自分に
      parent[edges[node][i]] = node;
      if(costs[node][i] %2 == 0){
	dfs(edges[node][i], col);
      }
      else{
	//反転
	dfs(edges[node][i], col ^ 1);
      }
    }
  }
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  REP(i, n-1){
    ll u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back(v);
    edges[v].push_back(u);
    costs[u].push_back(w);
    costs[v].push_back(w);    
  }
  dfs(1, 0);
  FOR(i,1,n+1){
    cout << color[i] << endl;
  }
    
  return 0;
}
