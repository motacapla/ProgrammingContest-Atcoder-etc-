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

const int MAX = 1000001;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}




ll tmp[30];
map<string, ll> mp;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  
  int n;
  cin >> n;
  vector<string> s(n);  
  REP(i,n) cin >> s[i];
  
  
  
  /*
  int n = 100000;
  vector<string> s(n);
  REP(i,n) s[i] = "ab";  
  */
  ll ans = 0LL;
  
  COMinit();
  
  REP(i, n){
    ll tmp[30];
    REP(j, 30) tmp[j] = 0;
    
    REP(j, s[i].size()){
      tmp[s[i][j]-'a']++;      
    }
    string val = "";	
    REP(k, 27) val += to_string(tmp[k]);    
    mp[val]++;
    //cerr << val << endl;
  }
  
  for(auto &e: mp){
    //cerr << e.second << endl;
    if(e.second == 1) continue;
    
    if(e.second > 1e4) {
      if(e.second % 2 == 0){
	ll tmp = e.second/2;      
	ans += tmp*(e.second-1);
      }
      else {
	ll tmp = (e.second-1)/2;      
	ans += tmp*(e.second);	
      }
    }
    else {
      ans += COM(e.second, 2);
    
    }
  }
  cout << ans << endl;
  
  return 0;
}
