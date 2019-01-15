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

double pi=acos(-1.0);
double eps=1e-14;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

P p[100000];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) cin >> p[i].first >> p[i].second;

  ll ans[3] = {};
  REP(i, n){
    vector<double> v;

    REP(j, n){
      if(i==j) continue;
      double d = atan2(p[j].second - p[i].second, p[j].first - p[i].first);
      //cout << "i:j = " << i << " " << j << " d: " << d << endl;
      if(d < 0) d += 2*pi;
      v.push_back(d);
    }
    
    sort(v.begin(), v.end());
    
    int p=1;
    int q=1;
    REP(j, n-1){
      while(p<v.size() && v[p]-v[j] < pi/2 - eps) p++;
      while(q<v.size() && v[q]-v[j] < 3*pi/2-eps) q++;
      int tmp=0;
      if(v[p]-v[j] >= pi/2 - eps && v[p]-v[j] <= pi/2 + eps){
	ans[1]++;
	tmp++;
      }
      if(v[q]-v[j] >= 3*pi/2 - eps && v[q]-v[j] <= 3*pi/2 + eps){
	ans[1]++;
      }
      ans[2] += max(0, q-p-tmp);
    }
  }
  ans[0] = (ll)n*(n-1)*(n-2)/6 - ans[1] - ans[2];

  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  
  return 0;
}
