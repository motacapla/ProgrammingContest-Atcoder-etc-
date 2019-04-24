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
#include <stack>
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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

vector<bool> sieve(size_t max){
  std::vector<bool> IsPrime;
  if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
    IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
  } 
  IsPrime[0] = false; // 0は素数ではない
  IsPrime[1] = false; // 1は素数ではない
  
  for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
    if(IsPrime[i]) // iが素数ならば
      for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
        IsPrime[i*j] = false;      // 素数ではない
  return IsPrime;
}

int vmax = 1e6;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<bool> primes = sieve(vmax);
  vector<int> prime_num(vmax, 0);
  int res = 0;
  REP(i, vmax+1){
    if(primes[i] && primes[(i+1)/2]) res++;
    prime_num[i] = res;
  }
  /*
  for(auto &e: prime_num) cout << e << " ";
  cout << endl;
  */

  int Q; cin >> Q;
  REP(i, Q){
    int l, r;
    cin >> l >> r;
    cout << prime_num[r] - prime_num[l-1] << endl;
  }
  return 0;
}
