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

// T have +-*/ and 0
template<class T> class BIT {
public:
    vector<T> dat;
    ll N;

    BIT(){}
    BIT(ll N) : N(N) { dat.assign(N,0); }
    // sum [0,i)
    T sum(ll i){
        ll ret = 0;
        for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
        return ret;
    }
    // sum [i,j)
    T sum(ll i, ll j) { return sum(j) - sum(i); }
    // add x to i
    void add(ll i, T x) { for(; i < N; i|=i+1) dat[i] += x; }
};


int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n; cin >> n;
  vector<ll> a(n);
  REP(i,n) {
    cin >> a[i];
  }
  //転倒してるのが蓄積される

  multiset<ll> ms;
  ms.insert(-1);
  for(auto &e: a) {
    //for(auto &m: ms) cerr << m << " ";
    //cerr << endl;
    auto p = ms.lower_bound(e);
    p--;
    //cerr  << " *p:" << *p << endl;
    if(*p >= 0) ms.erase(p);
    ms.insert(e);
  }
  cout << ms.size()-1 << endl;
  
  return 0;
}
