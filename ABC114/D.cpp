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

int sosu_c[25];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  ll ans = 0LL;
  
  int sosu[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  ll val = 1;

  REP(i, 25) sosu_c[i] = 0;  
  FOR(i, 2, n+1){
    val = val * i;        
    //check yakusu
    REP(i, 25){
      //wareru dake
      while(val % sosu[i] == 0){
	sosu_c[i]++;
	val /= sosu[i];
      }
    }        
  }

  REP(p, 25){
    if(sosu_c[p] >= 74) ++ans;
  }

  REP(p, 25) REP(q, 25){
    if(p == q) continue;    
    if(sosu_c[p] >= 24 && sosu_c[q] >= 2) ++ans;
    if(sosu_c[p] >= 14 && sosu_c[q] >= 4) ++ans;
  }

  //r, qの重複カウントを防ぐ
  REP(p, 25) FOR(q, p+1, 25) REP(r, 25) {
    if(p == r || q == r) continue;
    if(sosu_c[p] >= 4 && sosu_c[q] >= 4 && sosu_c[r] >= 2) ++ans;
  }
  
  cout << ans << endl;

  return 0;
}
