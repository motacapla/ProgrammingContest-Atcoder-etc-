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

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  string s;

  cin >> n >> k;
  cin >> s;

  vector<char> v;
  REP(i, s.size()) v.push_back(s[i]);
  sort(v.begin(),v.end());  

  int cnt = 0;
  REP(i, v.size()){
    if(v[i] != s[i]) cnt++;
  }
  if(k > cnt) {REP(i, v.size()) {cout << v[i];} cout << endl; return 0;}

  int vitr = 0;  
  //REP(i, s.size()){
  while(k>0){
    int opt = s.find(v[vitr]);    
    int cur = s.find(s[vitr]);
    cout << s << " " << opt << " " << cur << " k: " << k << endl;
    if(opt != cur) {
      swap(s[opt], s[cur]);
      k--;
      if(s[cur] != v[cur]) k--;      
    }    
    vitr++;
  }
  
  cout << s << endl;
  
  /*
  string l="", r="";
  REP(i, k) l += v[i];
  FOR(i, k, s.size()) r += v[i];
  */
  
  /*
  int cnt = k;
  REP(j, l.size()){
    if(l[j] != s[j]){
      //swap(l.find(l[j]), l.find(s[j]));
      cout << l.find(l[j]) << " " << l.find(s[j]) << endl;
      cnt-=2;
    }
    if(cnt == 0) break;
  }
  cout << l << r << endl;
  */
  
  return 0;
}
