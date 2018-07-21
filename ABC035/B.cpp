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
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

int
main(void){
  int t;
  string s;
  cin >> s >> t;

  ll x=0LL, y=0LL;
  ll count=0LL;

  REP(i, s.size()){
    if(s[i] == 'U'){
      ++y;
    }
    else if(s[i] == 'D'){
      --y;
    }
    else if(s[i] == 'L'){
      --x;
    }
    else if(s[i] == 'R'){
      ++x;
    }
    else{
      ++count;
    }    
  }

  //cout << "x,y" << x <<" " << y << endl;
  
  if(t==1){
    cout << abs(x) + abs(y) + count << endl;
  }else{
    if(abs(x) + abs(y) >= count) cout << abs(x) + abs(y) - count << endl;
    else{
      if((abs(x) + abs(y))%2 != 0 && count%2 != 0) {
	cout << "0" << endl;
      }
      else if((abs(x) + abs(y))%2 == 0 && count%2 != 0) {
	cout << "1" << endl;
      }
      else if((abs(x) + abs(y))%2 != 0 && count%2 == 0) {
	cout << "1" << endl;
      }
      else{
	cout << "0" << endl;
      }
    }
  }
  
  return 0;
}
