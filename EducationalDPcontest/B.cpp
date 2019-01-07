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

int h[1000000];
int dp[1000000];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n, k;  
  cin >> n >> k;

  REP(i, n) {
    int tmp;
    cin >> tmp;
    h[i] = tmp;
  }
  REP(i, n) dp[i] = INT_MAX;
  
  dp[0] = 0;
  FOR(i, 1, k+1) dp[i] = abs(h[i]-h[0]);

  REP(i, n) {
    int tmp = INT_MAX;
    REP(j, k){
      dp[i+k] = min(dp[i+k], dp[i+j]+abs(h[i+j]-h[i+k]));      
    //dp[i+2] = min(dp[i]+abs(h[i+2]-h[i]), dp[i+1]+abs(h[i+2]-h[i+1]));
    }
    /*
    REP(j, n) cout << dp[j] << " ";
    cout << endl;
    */
  }
  
  cout << dp[n-1] << endl;
  
  return 0;
}
