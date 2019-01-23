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

  string s;
  cin >> s;
  string s1 = "dream";
  string s2 = "dreamer";
  string s3 = "erase";
  string s4 = "eraser";
  
  bool s1_f=false, s2_f=false, s3_f=false, s4_f=false;
  int i = s.size()-1;      
  while(s.size() > 0){
    s1_f=false, s2_f=false, s3_f=false, s4_f=false;
    REP(j, 3){
      if(s1[s1.size()-1-j] != s[i-j]) s1_f = true;
      if(s2[s2.size()-1-j] != s[i-j]) s2_f = true;
      if(s3[s3.size()-1-j] != s[i-j]) s3_f = true;
      if(s4[s4.size()-1-j] != s[i-j]) s4_f = true;      
    }
    if(s1_f && s2_f && s3_f && s4_f){cout << "NO" << endl; return 0;}
    if(!s1_f) s.erase(s.size()-s1.size(),s.size());
    if(!s2_f) s.erase(s.size()-s2.size(),s.size());
    if(!s3_f) s.erase(s.size()-s3.size(),s.size());
    if(!s4_f) s.erase(s.size()-s4.size(),s.size());
    i = s.size()-1;
  }
  cout << "YES" << endl;
  
  return 0;
}
