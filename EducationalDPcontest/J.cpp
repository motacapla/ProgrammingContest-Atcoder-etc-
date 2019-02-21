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

const int MAXN = 310;

ll n;
map<int,int> mp;
double dp[MAXN][MAXN][MAXN];

double dfs(ll i, ll j, ll k){
  if(dp[i][j][k]>=0) return dp[i][j][k];
  if(i == 0 && j == 0 && k == 0) return 0.0;
  double res=0.0;
  double ijk = (double)i+j+k;
  res += n/ijk;
  if(k > 0) res += dfs(i, j+1, k-1) * (double)k/ijk;
  if(j > 0) res += dfs(i+1, j-1, k) * (double)j/ijk;
  if(i > 0) res += dfs(i-1, j, k) * (double)i/ijk;
  return dp[i][j][k] = res;  
}

int
main(void){
  cin >> n;
  REP(i,n) {
    int a;
    cin >> a;
    mp[a]++;
  }
  int one=0, two=0, three=0;
  for(auto &m: mp){
    if(m.first == 1) one+=m.second;
    if(m.first == 2) two+=m.second;
    if(m.first == 3) three+=m.second;
  }
  //cout << one << " " << two << " " << three << endl;
  memset(dp, -1, sizeof(dp));
  cout << fixed << setprecision(10) << dfs(one,two,three) << endl;
  
  return 0;
}
