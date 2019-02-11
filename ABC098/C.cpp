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

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
const int INF=1e9;
int sum_w[300100];
int sum_e[300100];
int num;
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;
  
  //1-indexed
  sum_w[0] = 0;
  sum_e[0] = 0;  
  REP(i, n){
    if(s[i] == 'W') {
      sum_w[i+1] = sum_w[i]+1;
      sum_e[i+1] = sum_e[i];
    }
    if(s[i] == 'E'){
      sum_e[i+1] = sum_e[i]+1;
      sum_w[i+1] = sum_w[i];      
    }
  }
  ll tmp, ans=INF;
  FOR(leader,1,n+1){    
    //cout << "migi E:" << sum_e[n]-sum_e[leader] << endl;
    //cout << "hidari W:" << sum_w[leader-1]-sum_w[0] << endl;
    tmp =  sum_e[n]-sum_e[leader] +  sum_w[leader-1]-sum_w[0];
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
