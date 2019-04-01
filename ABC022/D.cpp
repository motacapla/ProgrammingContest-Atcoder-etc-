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
#include <stack>
#include <bitset>

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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

double dist(double a, double x, double b, double y){
  return sqrt(pow((a-x), 2) + pow((b-y), 2));
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<pair<double,double>> A(n), B(n);
  pair<double, double> a, b;
  a.first = 0, a.second = 0;
  REP(i, n){
    cin >> A[i].first >> A[i].second;
    a.first += A[i].first;
    a.second += A[i].second;
  }
  a.first /= n; a.second /= n;
  b.first = 0, b.second = 0;
  REP(i, n){
    cin >> B[i].first >> B[i].second;
    b.first += B[i].first;
    b.second += B[i].second;
  }  
  b.first /= n; b.second /= n;

  double dist_a=0, dist_b=0;
  REP(i, n){
    dist_a = max(dist_a, dist(a.first, A[i].first, a.second, A[i].second));
    dist_b = max(dist_b, dist(b.first, B[i].first, b.second, B[i].second));    
  }
  //cerr << dist_a << " " << dist_b << endl;
  cout << fixed << setprecision(10) << dist_b/dist_a << endl;
  
  return 0;
}
