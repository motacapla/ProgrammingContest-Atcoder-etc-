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

ll a[100001], b[100001];
ll diff[100001];

int
main(void){  
  ios_base::sync_with_stdio(false);

  ll n=0LL, mns=0LL, pls=0LL;
  ll sum_minus = 0LL;
  cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];

  ll sum_a=0LL, sum_b=0LL;
  REP(i, n) {
    sum_a += a[i];
    sum_b += b[i];
    diff[i] = a[i] - b[i];
    
    if(diff[i] < 0) {
      sum_minus += diff[i];
    }
  }
  if(sum_a < sum_b) {cout << "-1" << endl; return 0;}
  sum_a = sum_a - sum_b; 

  sort(diff, diff+n, greater<ll>());

  //cout << sum_minus << endl;
  
  int itr = 0;
  //sum_a = 0;
  while(sum_minus < 0){
    sum_minus += diff[itr];
    mns++;
    itr++;
  }

  //cout << diff[0] <<endl;

  sum_a = 0;
  REP(i, itr){
    sum_a += diff[i];
  }
  
  REP(i, n){
    if(diff[i] < 0){
      sum_a += diff[i];
      //cout << "sum_a: " << sum_a << " diff[" << i << "]: " << diff[i] << endl;      
      if(sum_a < 0) break;
      pls++;
    }
  }

  
  cout << pls+mns << endl;
  
  return 0;
}
