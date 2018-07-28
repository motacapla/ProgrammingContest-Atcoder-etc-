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

ll labs(ll a, ll b){
  if(a<b) return b-a;
  else return a-b;
}

int
main(void){  
  ll x;
  cin >> x;

  ll ans = 0LL;
  ll i=0LL;
  for(i=1; i+ans<x; ++i){    
    ans += i;
    cout << i << " " << ans << endl;
  }

  cout << i << endl;;
 
  return 0;
}

  /*
  FOR(i, 1, x){
    l = labs(x, dp[i-1] - i);
    r = labs(x, dp[i-1] + i);
    m = labs(x, dp[i-1]);
    cout << "l,r,m=" << l << " " << r << " " << m << endl;    
    ll m_v = min(min(l, r), m);
    cout << "m_v=" << m_v << endl;
    dp[i] = labs(x, m_v);
    if(m_v == 0) break;
    ++count;        
  }
  cout << count << endl;
  */
  /*
  FOR(i, 0, x+1){
    FOR(j, 0, x+1){
      if(j >= i) dp[i+1][j] = max(dp[i][j-i]+i, dp[i][j]);
      else dp[i+1][j] = dp[i][j];      
      cout << "dp[" << i << "," << j << "]:" << dp[i][j] << endl;    
      count++;    
      if(dp[i+1][j] == x) break;        
    }
  }
  */
