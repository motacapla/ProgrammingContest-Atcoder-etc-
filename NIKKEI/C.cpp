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

pair<ll, ll> ab[100001];
pair<ll, ll> sum[100001];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) {
    cin >> ab[i].first >> ab[i].second;
    sum[i].first = (ll)ab[i].first+(ll)ab[i].second;
    sum[i].second = i;
  }
  sort(sum, sum+n, greater<pair<ll, ll>>());

  //cout << sum[0].first << " " << sum[0].second << endl;
  

  int ii=0;
  ll tkhs = 0LL, aoki = 0LL;
  while(ii<n){
    //cout << "tkhs: " << tkhs << " aoki: " << aoki << " ii: " << ii << endl;    
    tkhs += ab[sum[ii].second].first;
    ii++;
    if(ii >= n) break;
    aoki += ab[sum[ii].second].second;
    ii++;
  }

  cout << tkhs-aoki << endl;
  
  return 0;
}
