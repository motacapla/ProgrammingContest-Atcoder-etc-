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

const int MAX_V = 1e6;
int n,m;
vector<int> G[MAX_V];
int dp[MAX_V];
//メモリ犠牲
bool visited[MAX_V];

int dfs(int v){
  if(visited[v]) return dp[v];
  visited[v] = true;
  int val = 0;
  REP(to, G[v].size()){
    val = max(val, dfs(G[v][to])+1);
  }
  return dp[v] = val;
}

int
main(void){  
  cin >> n >> m;

  REP(i, m){
    int x, y;
    cin >> x >> y;
    x--;y--;
    G[x].push_back(y);
  }
  //時間犠牲
  //REP(i, MAX_V) dp[i] = -1;
  int ans = 0;
  REP(i, n) {
    ans = max(ans, dfs(i));
  }
  cout << ans << endl;
  return 0;
}
