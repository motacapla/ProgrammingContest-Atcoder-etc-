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

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

priority_queue<int> q_descending;
priority_queue<int, vector<int>, greater<int> > q_ascending;

vector<string> v;
map<string, int> mp;

int
main(void){  
  ios_base::sync_with_stdio(false);

  int k;
  string s;
  cin >> s >> k;

  REP(i, s.size()) {
    //cout << "i:" << i << endl;
    string stmp = "";    
    FOR(j, i, i+k){
      if(j == s.size()) break;
      stmp += s[j];
      if(mp[stmp] != 0) continue;
      v.push_back(stmp);
      mp[stmp]++;
      //cout << "stmp:" << stmp << endl;
    }
  }

  sort(v.begin(), v.end());

  /*
  for(auto itr = v.begin(); itr != v.end(); ++itr){
    cout << *itr << endl;
  }
  */

  cout << v[k-1] << endl;
  
  return 0;
}
