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
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

int
main(void){
  ll n, q;
  cin >> n >> q;
  ll l[q], r[q];

  int cnt[n] = {};
  
  REP(i, q) {
    cin >> l[i] >> r[i];
    /*
    FOR(j, l[i], r[i]+1){
      ++cnt[j-1];
    }
    */
    cnt[l[i]-1]++;
    cnt[r[i]]--;
  }

  FOR(i, 0, n){
    if(i != 0) cnt[i] = cnt[i] + cnt[i-1];
    if(cnt[i]%2 == 0) cout << "0";
    else cout << "1";     
  }

  /*
  REP(i, n){
    if(cnt[i]%2 == 0) cout << "0";
    else cout << "1"; 
  }
  */
  cout << "\n";
  
  return 0;
}
