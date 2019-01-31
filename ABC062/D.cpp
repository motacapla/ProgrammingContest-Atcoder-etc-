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
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

priority_queue<int> r;
priority_queue<int, vector<int>, greater<int> > l;

//解説AC
//n = 10^5 ... PQ -> n^2logn -> nlogn
//http://yebityon.hatenablog.com/entry/2017/11/05/000548

int a[300010];
ll mae, usr;

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, 3*n){
    cin >> a[i];
    if(i < n) {l.push(a[i]); mae+=a[i];}
    if(i >= n*2) {r.push(a[i]); usr+=a[i];}
  }
  vector<ll> p, q;
  p.push_back(mae);
  q.push_back(usr);

  ll ans = -1e9*1e9;  
  REP(i, n){
    l.push(a[n+i]);
    r.push(a[2*n-i-1]);
    mae += a[n+i] - l.top();
    usr += a[2*n-i-1] - r.top();
    p.push_back(mae);
    q.push_back(usr);
    l.pop(); r.pop();
  }
  
  REP(i, q.size()) ans=max(ans, p[i]-q[n-i]);
  cout << ans << endl;  

  return 0;
}
