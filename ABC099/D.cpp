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

int D[31][31];
int c[501][501];
int cnt[3][31];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int N, C;
  cin >> N >> C;
  REP(i, C) REP(j, C) cin >> D[i][j];
  REP(i, N) REP(j, N) cin >> c[i][j];

  REP(i, N) REP(j, N) cnt[(i+j+2)%3][c[i][j]-1]++;

  //cout << cnt[0] << " vs " << cnt[1] << " vs " << cnt[2] << endl;

  int ans = 1 << 30;  
  REP(i, C) REP(j, C) if(i != j) REP(k, C) if(i != k && j != k) {
      int tmp = 0;
      REP(l, C) tmp += D[l][i] * cnt[0][l];
      REP(l, C) tmp += D[l][j] * cnt[1][l];
      REP(l, C) tmp += D[l][k] * cnt[2][l];
      if(tmp < ans) ans=tmp;
    }

  cout << ans << endl;
  
  return 0;
}
