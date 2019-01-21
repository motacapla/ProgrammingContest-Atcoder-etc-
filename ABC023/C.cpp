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

int row[100001], col[100001];
int cnr[100001], cnc[100001];
map<int, int> mpr, mpc;

int
main(void){  
  ios_base::sync_with_stdio(false);

  int r, c, k, n;
  cin >> r >> c >> k >> n;
  REP(i, n) {
    cin >> row[i] >> col[i];
    //アメちゃんあたりの行or列数
    cnr[row[i]-1]++, cnc[col[i]-1]++;
  }
  //行or列あたりのアメちゃんの数  
  REP(i, r) mpr[cnr[i]]++;
  REP(i, c) mpc[cnc[i]]++;

  //REP(i, r) cout << mpr[cnr[i]] << endl;
  
  ll ans = 0LL;
  REP(i, k+1){
    ans += mpc[i] * mpr[k-i];
  }
  
  REP(i, n){
    r = cnr[row[i]-1] + cnc[col[i]-1];
    if(r == k) ans--;
    if(r == k+1) ans++;
  }
    
  cout << ans << endl;
  
  return 0;
}
