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

//ベルマンフォード法
//https://abc061.contest.atcoder.jp/submissions/4484303

struct edge {ll to, cost;};
vector<vector<edge>> g;
const ll INF = 1e18;
const int MAX_N = 1e5;

ll dist[MAX_N];
ll n,m;

vector<pair<ll, ll>> edge;
vector<ll> cost;

bool bellman_ford(ll s){
  REP(i,n) dist[i] = INF;  
  dist[s] = 0;
  bool flag = true;
  REP(v, n){
    flag = false;
    REP(i, m){
      ll s = edge[i].first, t = edge[i].second;
      if(dist[s] != INF && dist[t] > dist[s] + cost[i]){
	dist[t] = dist[s] + cost[i];
	flag = true;	  	
	//n回目に n-1 に更新がある -> 負のサイクル
	if(v == n-1 && t == n-1){
	  return true;
	}
      }      
    }
    if(!flag) break;
  }
  return false;
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;  
  
  REP(i, m){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--; c*=-1;
    edge.push_back(make_pair(a, b));
    cost.push_back(c);
  }
  
  cout << (!bellman_ford(0) ? to_string(-dist[n-1]) : "inf" ) << endl;
  
  return 0;
}


/*
bool bellman_ford_naive(ll s){
  REP(i,n) dist[i] = INF;
  dist[s] = 0;

  bool negative_cycle = false;

  REP(i, n){
    REP(v, n){
      for(edge e: g[v]){
	if(dist[v] != INF && dist[e.to] > dist[v] + e.cost){
	  dist[e.to] = dist[v] + e.cost;
	  //n回目に n-1 に更新がある -> 負のサイクル
	  if(i == n-1 && e.to == n-1){
	    dist[e.to] = -INF;
	    negative_cycle = true;
	  }
	}
      }
    }
  }
  return negative_cycle;
}
*/
