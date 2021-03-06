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

int a[575];
//map<int,int> mp;
int mp[9];

int
main(void){  
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) {
    cin >> a[i];
    if(a[i] < 400) mp[0]++;
    else if(a[i] < 800) mp[1]++;
    else if(a[i] < 1200) mp[2]++;
    else if(a[i] < 1600) mp[3]++;
    else if(a[i] < 2000) mp[4]++;
    else if(a[i] < 2400) mp[5]++;
    else if(a[i] < 2800) mp[6]++;
    else if(a[i] < 3200) mp[7]++;
    else mp[8]++;
  }

  int minn=0;
  int non_niji=0, niji=0;
  REP(i, 9){
    if(i == 8) continue;
    else if(mp[i]) minn++;			 
  }
 
  cout << max(minn, 1) << " " << minn + mp[8] << endl;
  
  return 0;
}
