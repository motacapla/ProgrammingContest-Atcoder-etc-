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

bool r[11][11];

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, a, b;
  cin >> n >> m;
  REP(i, m) {
    cin >> a >> b;
    a--; b--;
    r[a][b] = true;
    r[b][a] = true;
  }

  REP(i, n){
    vector<int> v;
    REP(j, n) {
      if(r[i][j]) v.push_back(j);
    }
    vector<int> vv;
    int ans = 0;
    for(auto itr=v.begin(); itr != v.end(); itr++){
      REP(j, n){
	if(j != i && r[*itr][j]) vv.push_back(j);
      }
    }
    map<int, int> mp;
    for(auto itr=vv.begin(); itr != vv.end(); itr++){
      //cout << *itr << endl;
      if(!r[i][*itr] && mp[*itr] == 0) {
	ans++;
	mp[*itr]++;
      }
    }
    cout << ans << endl;
  }

  
  return 0;
}
