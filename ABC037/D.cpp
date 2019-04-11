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

ll ans;
int h, w;
int a[1010][1010];
ll memo[1010][1010];
int dh[4] = {-1, 1, 0, 0};
int dw[4] = {0, 0, -1, 1};

bool check(int a, int b){
  return (0 <= a && a < h && 0 <= b && b < w);
}

ll dfs(int hh, int ww){
  if(memo[hh][ww] != -1) return memo[hh][ww];
  //cerr << "hh: " << hh << " ww: " << ww << endl;
  int res = 1;
  REP(i, 4){
    int y = hh + dh[i];
    int x = ww + dw[i];    
    if(!check(y, x) || a[hh][ww] >= a[y][x]) continue;
    (res += dfs(y, x))%MOD;
  }
  return memo[hh][ww] = res;
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  REP(i, h) REP(j, w) {
    cin >> a[i][j];
    memo[i][j] = -1;
  }
  REP(i, h) REP(j, w) (ans += dfs(i, j))%MOD;
  cout << ans << endl;
  return 0;
}
