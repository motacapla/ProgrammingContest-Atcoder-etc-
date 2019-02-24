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
int l[10];
const int INF = 1e9;
int n, A, B, C;  

//n<=8, 4^N -> ok
ll dfs(int cur,int a, int b, int c){
  if(cur == n){
    if(min(min(a, b), c) > 0){
      return abs(a-A)+abs(b-B)+abs(c-C)-30;
    }
    else return INF;
  }
  //入れない, Aに入れる, Bに入れる, Cに入れる
  ll ret0 = dfs(cur+1, a, b, c);
  ll ret1 = dfs(cur+1, a+l[cur], b, c)+10;
  ll ret2 = dfs(cur+1, a, b+l[cur], c)+10;
  ll ret3 = dfs(cur+1, a, b, c+l[cur])+10;
  return min(min(ret0, ret1), min(ret2, ret3));
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> A >> B >> C;
  REP(i, n) cin >> l[i];

  cout << dfs(0, 0, 0, 0) << endl; 
  
  return 0;
}
