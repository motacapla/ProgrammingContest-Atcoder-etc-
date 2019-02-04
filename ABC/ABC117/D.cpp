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
#include <bitset>

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

ll a[100100];
ll cnt[100100];
ll n, k;
ll func(ll x){
  ll ans = 0LL;
  REP(i, n) ans += x ^ a[i]; 
  return ans;
}

ll calc(ll x){
  ll sum = 0LL;
  REP(i, 60){
    if(x & (1LL<<i)) sum += (1LL<<i)*max(cnt[i], n-cnt[i]);
    else sum += (1LL<<i) * cnt[i];
  }
  return sum;
}
//int cnt[40] = {};

/* 解説AC, 上位bitから*/

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  REP(i, n) {
    cin >> a[i];
    ROF(j, 60, 0){
      if(a[i] & (1LL<<j)) cnt[j]++;
    }
  }
  ll ans = max(calc(0), calc(k));
  REP(i, 60){
    int j = 60-1-i;
    if((1LL<<j) & k) ans = max(ans, calc((k^(1LL<<j))|((1LL<<j)-1)));
  }
  cout << ans << endl;

  return 0;
}
