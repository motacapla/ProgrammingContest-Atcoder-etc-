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

int n, g, e, girl[110], a, b, ans;
bool visited[110];
bool graph[110][110];

//解説AC
//dfsで各マークしている女の子たちが高橋くんの友達かどうかを調べる
//dfs同経路上の女の子は一括してカウント -> つまりカウントをスキップ

bool dfs(int v){
  if(!v) return true;
  else{
    REP(i, n){
      if(!visited[i] && graph[v][i]){
	visited[i] = true;
	graph[v][i] = false;
	if(dfs(i)) return true;
	graph[v][i] = true;
      }
    }
  }
  return false;
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> g >> e;
  REP(i, g) cin >> girl[i];
  REP(i, e){
    cin >> a >> b;
    graph[a][b] = graph[b][a] = true;
  }

  REP(i, g){
    REP(j, n) visited[j] = false;
    visited[girl[i]] = true;
    if(dfs(girl[i])) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
