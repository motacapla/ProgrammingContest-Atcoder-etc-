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

ll a[200500];
const ll INF = 1e10;

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  REP(i, n)cin >> a[i];

  //使わない
  int zero_place = lower_bound(a, a+n, 0)-a;

  //相対的にずらしていく, 0からの相対位置に応じて足す
  ll ans = INF;
  for(int i=0; i+k-1<n; i++){
    ll tmp = a[i+k-1]-a[i];
    //両方とも左
    if((a[i]<0) && (a[i+k-1]<0)) tmp += abs(a[i+k-1]);
    //両方とも右
    if((a[i]>0) && (a[i+k-1]>0)) tmp += a[i];
    //間
    if((a[i]<0) && (a[i+k-1]>0)) tmp += min(-a[i], a[i+k-1]);
    ans = min(ans, tmp);
  }
  
  cout << ans << endl;
  
  return 0;
}


  /*
  ll ans_l = 0LL;  
  FOR(i, zero_place, zero_place+(k-(n/2))) ans_l += abs(x[i]);  
  ans_l *= 2;
  ans_l += abs(x[0]);
  ans = min(ans, ans_l);

  //cout <<"1: " << ans_l << endl;
  
  ans_l = 2*abs(x[0]);
  ans_l += abs(x[zero_place+(k-(n/2))-1]);
  ans = min(ans, ans_l);
  
  //cout << "2: " << ans_l << endl;
   
  ll ans_r = 0LL;
  //ROF(i, zero_place, zero_place-(k-(n/2))) ans_r += abs(x[i]);
  ans_r += abs(x[zero_place-(k-(n/2))]);
  ans_r *= 2;
  ans_r += abs(x[n-1]);
  ans = min(ans, ans_r);

  //cout << "3: " << ans_r << endl;
  
  ans_r = 2*abs(x[n-1]);
  //ROF(i, zero_place, zero_place-(k-(n/2))) ans_r += abs(x[i]);
  ans_r += abs(x[zero_place-(k-(n/2))]);
  cout << x[zero_place-(k-(n/2))] << endl;
  ans = min(ans, ans_r);

  //cout << "4: " << ans_r << endl;

  if(zero_place >= k){
    cout << "left-enough:" << abs(x[zero_place-(k-(n/2))]) << endl;
    ans = min(ans, (ll)abs(x[zero_place-(k-(n/2))]));    
  }
  if(n-zero_place >= k){
    cout << "right-enoguth:" << abs(x[zero_place+k-1]) << endl;
    ans = min(ans, (ll)abs(x[zero_place+k-1]));
  }
  */
  
