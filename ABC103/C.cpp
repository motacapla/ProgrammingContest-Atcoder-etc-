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

ll lcm(ll a, ll b){
  if(a > b){
    return (a / __gcd(a, b)) * b;
  }else{
    return (b / __gcd(a, b)) * a;
  }
}

int
main(void){  
  int n;
  cin >> n;
  ll a[n];
  ll max_a = 0LL;
  REP(i, n) {
    cin >> a[i];
    //if(max_a < a[i]) max_a = a[i];
  }

  /*
  ll ans = a[0];
  FOR(i, 1, n){
    ans = lcm(a[i], ans);
  }
  
  ll hoge = 0LL;
  REP(i, n) hoge += (ans-1) % a[i];
  cout << hoge << endl;
  */

  ll ans = 0LL;
  REP(i, n) ans += a[i]-1;
  cout << ans << endl;
  return 0;
}
