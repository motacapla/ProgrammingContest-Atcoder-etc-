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

int chmin(int tri1, int tri2, int tri3, int ans){
  return min(ans, max(tri1, max(tri2, tri3)) - min(tri1, min(tri2, tri3)));
}

//解説AC
//https://atcoder.jp/contests/abc062/submissions/4242775
/*
 _ _ _ _ _
|  |      |
|  | - - -|
|  |      |
 - - - - -
 __ __
|  |  |
|__|__|
|_____|

 */
ll H,W;
const int INF = 1e9;

ll solve(ll height, ll width){
  ll res = INF;
  ll smax, smin;
  ll sa, sb, sc;
  FOR(h, 1, height){
    sa = h*width;
    ll w = width/2;
    sb = w * (height - h);
    sc = (width - w) * (height - h);    
    smax = max(sa, max(sb, sc));
    smin = min(sa, min(sb, sc));
    res = min(smax-smin, res);

    sb = ((height-h)/2) * width;
    sc = height * width - sa - sb;
    smax = max(sa, max(sb, sc));
    smin = min(sa, min(sb, sc));
    res = min(smax-smin, res);    
  }
  return res;
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  ll ans = 0LL;
  cin >> H >> W;
  if(H%3 == 0 || W%3 == 0){cout << 0 << endl; return 0;}
  ans = min(solve(H,W), solve(W,H));
  cout << ans << endl;
  
  return 0;
}
