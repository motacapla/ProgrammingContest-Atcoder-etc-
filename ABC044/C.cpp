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

uintmax_t combination(unsigned int n, unsigned int r) {
  if ( r * 2 > n ) r = n - r;
  uintmax_t dividend = 1;
  uintmax_t divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}

int
main(void){  
  int n, a;
  int x[51] = {};
  ll ans = 0LL;  
  int m_x = 0;
  cin >> n >> a;

  REP(i, n) {
    cin >> x[i];
    if(m_x < x[i]) m_x = x[i];
  }
  int n_x[51] = {};
    
  REP(i, n) ++n_x[x[i]-1];
    
  int n_a = n_x[a-1];

  cout << n_a << endl;

  ans += pow(2, n_a) -1;
  
  cout << "a : " << ans << endl;
  
  int l = a-1, r = a+1;
  while(l >= 1 && r <= m_x){
    cout << "l,r = " << l << " " << r << endl;
    int n_l=n_x[l-1], n_r=n_x[r-1];
    ans += n_l * n_r * (1<<n_a);
    l--;
    r++;
    cout << "a : " << ans << endl;    
  }

  cout << ans << endl;
  
  return 0;
}
