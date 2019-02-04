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

vector<int> a, b, c;

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, 3){
    REP(j, n){
      int tmp;
      cin>>tmp;
      switch(i){
      case 0:
	a.push_back(tmp);
	break;
      case 1:
	b.push_back(tmp);
	break;
      case 2:
	c.push_back(tmp);
	break;
      }
    }
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0LL;
  REP(i, n){
    auto ab = lower_bound(a.begin(), a.end(), b[i]);
    auto bc = upper_bound(c.begin(), c.end(), b[i]);
    ll d1 = distance(a.begin(), ab);
    ll d2 = distance(bc, c.end());
    //cout << ab << " " << bc << endl;
    ans += d1*d2;
  }
  
  cout << ans << endl;
  
  return 0;
}


  /*
  //O(n^2logn)になりTLE
  REP(i, n){
    vector<int>::iterator it1 = upper_bound(b.begin(), b.end(), a[i]);
    if(n <= distance(b.begin(), it1)) continue;
    int cnt = distance(it1, b.end()), ii = 0;
    //cout << "cnt: " << cnt << endl;
    while(ii<cnt){
      vector<int>::iterator it2 = upper_bound(c.begin(), c.end(), b[n-cnt+ii]);
      if(n <= distance(c.begin(), it2)) continue;
      //cout << " a: " << a[i] << " b: " << *it1 << " c: "<< *it2 << endl;    
      ans += distance(it2, c.end());
      ii++;
    }
    //cout << distance(b.begin(), it1) << endl;
  }
  */
