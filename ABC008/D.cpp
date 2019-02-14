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
//https://ferin-tech.hatenablog.com/entry/2017/01/04/222320
//直感的にはこっち
//http://competitive-kivantium.hateblo.jp/entry/2016/12/16/120800
//一つ選んだら、残りも独立に求められる

ll dp[101][101][101][101];
ll x[32],y[32];
ll w, h, n;

ll dfs(int sx, int sy, int fx, int fy){
  if(dp[sx][sy][fx][fy]!=0) return dp[sx][sy][fx][fy];

  int ret = 0, gold = x[fx] - x[sx] + y[fy] - y[sy] - 3;
  //範囲内を調べる
  REP(i, n+1){
    //左上, 左下, 右上, 右下
    if(x[sx]<x[i] && x[i]<x[fx] && y[sy]<y[i] && y[i]<y[fy]) ret = max((ll)ret, dfs(sx,sy,i,i)+dfs(sx,i,i,fy)+dfs(i,sy,fx,i)+dfs(i,i,fx,fy)+gold);
  }
  return dp[sx][sy][fx][fy] = ret;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> w >> h >> n;
  x[0] = 0, y[0] = 0;
  FOR(i,1,n+1) cin >> x[i] >> y[i];
  x[n+1] = w+1, y[n+1] = h+1;

  cout << dfs(0,0,n+1,n+1) << endl;
  
  return 0;
}
