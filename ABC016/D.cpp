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
pair<double, double> xy[110];
pair<double, double> a, b;

bool cross_(double ax, double ay, double bx, double by, double x1, double y1, double x2, double y2){
  double a = (ax-bx) * (y1-ay) - (ay-by) * (x1-ax);
  double b = (ax-bx) * (y2-ay) - (ay-by) * (x2-ax);
  return a*b < 0;
}
bool cross(double ax, double ay, double bx, double by, double x1, double y1, double x2, double y2){
  return cross_(ax,ay,bx,by,x1,y1,x2,y2) && cross_(x1,y1,x2,y2,ax,ay,bx,by);
}
int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> a.first >> a.second >> b.first >> b.second;
  int n;
  cin >> n;
  REP(i, n) cin >> xy[i].first >> xy[i].second;
  int cnt = 0;
  REP(i, n){
    int j;
    if(i == 0) j = n-1;
    else j = i-1;
    if(cross(a.first, a.second, b.first, b.second, xy[i].first, xy[i].second, xy[j].first, xy[j].second)) cnt++;
  }

  cout << (cnt/2)+1 << endl;
  
  return 0;
}
