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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

//vector<int> v = sieve_of_eratosthenes(p);
//for(auto &e: v) cout << e << endl;
vector<int> sieve_of_eratosthenes(int n) {
  vector<int> primes;
  for (int i = 2; i < n; ++i)
    primes[i] = i;
  for (int i = 2; i*i < n; ++i)
    if (primes[i])
      for (int j = i*i; j < n; j+=i)
        primes[j] = 0;
  return primes;
}

map<int, int> mp;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, p;
  cin >> n >> p;
  if(n == 1){ cout << p << endl; return 0; }
  ll lim = p;
  FOR(i,2,sqrt(lim)+1){
    while(p%i==0){
      p/=i;
      mp[i]++;
    }
  }
  //for(auto &e: mp) cout << e.first << " " << e.second << endl;

  ll ans = 1LL;
  for(auto &e: mp){
    ll num = e.second/n;
    REP(i, num){
      ans *= e.first;
    }
  }
  cout << ans << endl;
  
  return 0;
}
