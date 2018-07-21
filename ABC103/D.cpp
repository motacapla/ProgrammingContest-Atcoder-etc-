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

//区間スケジューリング問題の双対問題
//串刺し問題
//http://drken1215.hatenablog.com/entry/2018/07/21/224200

int
main(void){  
  int n, m;
  cin >> n >> m;
  
  vector <P> v;

  REP(i, m){
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x, y);
    v.push_back(make_pair(x, y));
  }

  sort(v.begin(), v.end());

  int l = v[0].first;
  int r = v[0].second;
  int ans = 1;

  FOR(i, 1, m){    
    if(v[i].first >= r){
      ans++;
      l = v[i].first;
      r = v[i].second;
    }
    else{
      l = max(l, v[i].first);
      r = min(r, v[i].second);
    }
    //cout << "l" << l << " r" << r << endl;
  }

  cout << ans << endl;
  
  return 0;
}
