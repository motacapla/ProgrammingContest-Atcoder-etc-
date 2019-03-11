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
typedef pair<ll, ll> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

//解説AC
//Priority queue
//https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/4548510
//
//O(nklogn) -> O((n+k)logn)

const int MAX_N = 100010;
//pair<ll, ll> ab[MAX_N];
priority_queue<P, vector<P>, greater<P> > pq;
ll b[MAX_N];
ll a;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n,k;
  cin >> n >> k;  
  REP(i,n) {
    cin >> a >> b[i];
    pq.push(P(a,i));
  }
  
  ll ans = 0LL;
  while(k>0){
    P now = pq.top(); pq.pop();
    a = now.first;
    ll idx = now.second;
    ans += a;
    pq.push(P(a+b[idx], idx));
    k--;
  }
  cout << ans << endl;
  return 0;
}
