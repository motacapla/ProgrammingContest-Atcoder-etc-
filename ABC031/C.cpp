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

int n;  
int a[100];

bool debug = false;

/*
int calc(int l, int r){
  int takahashi = 0, aoki = 0;

  int sum[n], sum_aoki = 0, sum_itr = 0;
  REP(i, n) sum[i] = 0;
  for(int i=l, j=0; i<n; i+=2, j++){
    sum[j+1] += sum[j] + a[i+1];
    if(sum_aoki < sum[j+1]){
      sum_aoki = sum[j+1];
      sum_itr = j;
    }
  }
  if(debug)cout << sum_itr << endl;
  
  for(int i=l; i<l+2*sum_itr; i+=2){
    takahashi += a[i];
    aoki += a[i+1];
  }
  if(debug) cout << "l: " << l << " r: " << r << " takahashi: " << takahashi <<  " aoki: " << aoki << endl;
  return takahashi;
}
*/

int
main(void){  
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i, n) cin >> a[i];

  int ans = -1e8;
  
  REP(i, n){
    int x = -1e8;
    int y = -1e8;    
    REP(j, n){
      if(i == j) continue;

      int l = min(i, j);
      int tmp_x = 0;
      int tmp_y = 0;
      REP(k, abs(i-j)+1){
	if(k%2) tmp_y += a[l+k];
	else tmp_x += a[l+k];
      }
      if(tmp_y > y){
	y = tmp_y;
	x = tmp_x;
      }
      /*
      else if(i < j){
	ans =  max(ans, calc(i, j));	
      }
      else{
	ans =  max(ans, calc(j, i));	
      }
      if(debug) cout << "i: " << i << " j: " << j << " ans: " << ans << endl;
      */
    }
    ans = max(ans, x);
  }

  cout << ans << endl;
  
  return 0;
}
