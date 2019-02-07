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

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

P aka[575];
P ao[575];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) {
    int x, y;
    cin >> x >> y;
    aka[i].first = x; aka[i].second = y;
  }
  REP(i, n) {
    int x, y;
    cin >> x >> y;
    ao[i].first = x; ao[i].second = y;
  }
  sort(aka, aka+n);
  sort(ao, ao+n);
  
  ll ans = 0LL;
  //for aka 
  vector<bool> used(n+1, false);
  
  REP(i, n){
    auto now = ao[i];
    int t = 0;
    int max_idx = -1;
    while(t<n && aka[t].first < now.first){
      if(aka[t].second < now.second && !used[t])
	{
	  if(max_idx == -1 || aka[max_idx].second < aka[t].second) max_idx=t;
	}
      t++;
    }
    if(max_idx == -1) continue;
    ans++;
    used[max_idx] = true;
  }
  cout << ans << endl;
  return 0;
}
