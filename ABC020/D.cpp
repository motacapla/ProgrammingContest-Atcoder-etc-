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
ll DIVIDE(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

//解説AC
//https://atcoder.jp/contests/abc020/submissions/4426507

ll n, k;

ll gcd(ll a, ll b){
  return b != 0 ? gcd(b, a%b) : a;
}
ll lcm(ll a, ll b){
  return ((a*b)%MOD/gcd(a, b));
}

ll divide[2000], sums[2000], ans;

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> n >> k;

  ll size = 0LL;
  for(int i=1; i*i <= k; i++){
    if(k%i) continue;
    divide[size] = i;
    size++;
    if(i*i!=k){
      divide[size] = k/i;
      size++;
    }
  }
  sort(divide, divide+size);

  ROF(i, size-1, 0){
    ll num = n/divide[i];
    sums[i] = num*(num+1)/2 % MOD * divide[i] % MOD;
    FOR(j, i+1, size) if(divide[j]%divide[i] == 0) sums[i] = (sums[i] + MOD - sums[j])%MOD;    
  }
  REP(i, size){
    ans = (ans + k/divide[i] * sums[i]%MOD)%MOD;
  }
  cout << ans << endl;
  return 0;
}
