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

int get_legs(int a, int b, int c){
  return a*2+b*3+c*4;
}

bool debug = true;

int
main(void){  
  int n, m;
  cin >> n >> m;
  int a, b ,c;
  bool f=false;
  int sum = 0;

  b = 0;
  REP(i, n+1){
    a = n - i;
    c = i;
    sum = get_legs(a, b, c);
    if(sum == m && a+b+c == n) {cout << a << " " << b << " " << c << endl; return 0;}   
  }

  b = 1;
  int nn = n-1;
  REP(i, nn+1){
    a = nn - i;
    c = i;
    sum = get_legs(a, b, c);    
    if(sum == m && a+b+c == n) {cout << a << " " << b << " " << c << endl; return 0;}   
  }

  cout << "-1 -1 -1" << endl;

  /*
  b = 0;  
  while(l<r){
    int mid = (l+r)/2;
    a = n - mid;
    c = mid;

    if(debug) cout << l << " " << mid << " " << r << endl;
    if(debug) cout << a << ":" << b << ":" << c << endl;
    
    sum = get_legs(a, b, c);
    if(sum > m) {
      if(r == mid) break;
      r = mid;
    }
    else if(sum < m){
      if(l == mid) break;
      l = mid;
    }
    else if(sum == m && a+b+c == n){
      f = true;
      break;
    }
  }
  if(f) {
    cout << a << " " << b << " " << c << endl;
    return 0;
  }


  l = 0; r = n; b = 1;
  int nn = n-1;
  while(l<r){
    int mid = (l+r)/2;
    a = nn - mid;
    c = mid;

    if(debug) cout << l << " " << mid << " " << r << endl;
    if(debug) cout << a << ":" << b << ":" << c << endl;    
    
    sum = get_legs(a, b, c);
    if(sum > m) {
      if(r == mid) break;      
      r = mid;
    }
    else if(sum < m){
      if(l == mid) break;      
      l = mid;
    }
    else if(sum == m && a+b+c == n){
      f = true;
      break;
    }
  }
  if(f) {
    cout << a << " " << b << " " << c << endl;
    return 0;
  }
  cout << "-1 -1 -1" << endl;
  */
  
  return 0;
}


