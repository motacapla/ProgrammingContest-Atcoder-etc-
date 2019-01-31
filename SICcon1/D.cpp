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

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

ll nl, nm;
ll a[10000001];

map<ll,ll> mp;
vector<set<ll>> vs(100001);

// vs -> multisetで書き直しするか

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  REP(i, m) cin >> a[i];

  ll r = 0LL, minlen = 1e8+1;
  ll sum = 0LL, vitr = 0LL;;
  REP(l, m){    
    while(r < m && sum < n){
      sum += a[r];
      r++;
    }
    if(minlen >= r-l && sum >= n){
      //check
      //cout << "l: " << l << " r: " << r << " sum: " << sum << " minlen: " << minlen << endl;      
      minlen = r-l;
      FOR(i, l, r){
	vs[vitr].insert(i);
      }
      vitr++;
    }
    if(l == r) r++;
    else sum -= a[l];
  }

  multiset<int> aa, tmp, res;
  int f = 0;
  bool flag = false;

  REP(i, vitr){
    if(minlen != vs[i].size()) continue;//vs[i].clear(); //いらないやつは消す
    else {
      tmp.clear();
      res.clear();
      for(auto itr=vs[i].begin(); itr!=vs[i].end(); itr++) {
	tmp.insert(*itr);       
      }
      f++;
      flag = true;
    }
    if(f == 1) aa = tmp;
    if(flag) set_intersection(aa.begin(), aa.end(), tmp.begin(), tmp.end(), inserter(res, res.end()));
    flag = false;
  }
  if(f == 1) res = aa;
  cout << res.size() << endl;
  
  return 0;
}
