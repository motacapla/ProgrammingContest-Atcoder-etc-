//解説AC
//https://atcoder.jp/contests/abc142/submissions/7794118
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
const int MOD=1e9+7;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

const int N = 1010;

struct edge {
    int to;
    int cost;
};
vector<int> G[N];
int n, m;
const int INF = 1e8;
deque<int> path;
int Next[N];
bool vis[N];

int dfs(int u, int start, int sz) {
  int min_sz = INF;
  for (int v: G[u]) {
    if (!vis[v]) {
      if (v == start) {
        Next[u] = v;
        return sz + 1;
      }
      vis[v] = true;
      int tmp = dfs(v, start, sz + 1);
      if (tmp < min_sz) {
        min_sz = tmp;
        Next[u] = v;
      }
    }
  }
  return min_sz;
}
 
void cycleRec(int start) {
  path.clear();
  path.emplace_back(start);
  int v = Next[start];
  while (v != start) {
    path.emplace_back(v);
    v = Next[v];
  }
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(int i=0; i<m; ++i){
      int a, b;
      cin >> a >> b;
      a--, b--;
      G[a].push_back(b);
  }    
  int start = -1, min_sz = INF;
  REP(i, n) {
    REP(j, n) {
      vis[j] = false;
      Next[j] = -1;
    }
    int sz = dfs(i, i, 0);
    if (sz < min_sz) {
      start = i;
      min_sz = sz;
    }
  }
  if (start == -1) {
    printf("-1\n");
  } else {
    REP(i, n){
      vis[i] = false;
      Next[i] = -1;
    }
    dfs(start, start, 0);
    cycleRec(start);
    printf("%d\n", (int) path.size());
    for (int i = 0; i < (int) path.size(); ++i) {
      printf("%d\n", path[i] + 1);
    }
  }

  return 0;
}
