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

int x[101], y[101];
ll h[101];

ll tmp[101];

pair<ll, ll> p[101];

int get_height(int cx, int cy, int n){
  int i = 0;
  for(; h[i] == 0; i++){}
  int ch = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
  REP(i, n) if(h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) return 0;
  //REP(i, n) if(h[i] != ch - abs(x[i] - cx) - abs(y[i] - cy)) return 0;

  return ch;
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) cin >> x[i] >> y[i] >> h[i];
  
  REP(cy, 101) REP(cx, 101) {
    int ch = get_height(cx, cy, n);
    if(ch > 0) {cout << cx << ' ' << cy << ' ' << ch << endl; return 0;}
  }
   
  return 0;
}
