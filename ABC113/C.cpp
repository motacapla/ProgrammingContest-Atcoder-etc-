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

const int MAXN = 100010;
ll p[MAXN], y[MAXN];
vector<ll> pref[MAXN];


//idxがグループによって異なる → いくつかの配列に分ける
//sort済み配列として、lower_bound(begin, end, value)-begin ... その値のidxがわかる

//AC

int
main(void){
  int n, m;
  cin >> n >> m;
  REP(i, m){
    cin >> p[i] >> y[i];
    p[i]--;
    pref[p[i]].push_back(y[i]);
  }

  REP(i, n) sort(pref[i].begin(), pref[i].end());

  //1-indexed: + 1
  REP(i, m) printf("%06d%06d\n", p[i]+1, lower_bound(pref[p[i]].begin(), pref[p[i]].end(), y[i])-pref[p[i]].begin()+1);
  
}

