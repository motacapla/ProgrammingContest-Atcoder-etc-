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

const int MAX_V = 110;
int d[MAX_V][MAX_V];

void setCost(int d[MAX_V][MAX_V], int s, int e, int cost){
    d[s][e] = d[e][s] = cost;
}

int
main(void){  
  int n, m;  
  cin >> n >> m;
  const int V = n;
  
  FOR(i, 1, V+1){
    FOR(j, 1, V+1){
      if (i == j) d[i][j] = 0;
      else d[i][j] = MOD;
    }
  }
  
  ll a[m+1], b[m+1], c[m+1];
  FOR(i, 1, m+1){
    cin >> a[i] >> b[i] >> c[i];
    setCost(d, a[i], b[i], c[i]);
  }
  
  // Warshall Floyd
  FOR(k, 1, 1+V){
    FOR(i, 1, 1+V){
      FOR(j, 1, 1+V){
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans=0;
  FOR(i, 1, 1+m){
    if(d[a[i]][b[i]] < c[i]) ++ans;
  }

  cout << ans << endl;

  return 0;
}
