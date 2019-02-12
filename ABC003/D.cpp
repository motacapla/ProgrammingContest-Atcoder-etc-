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

/*
const ll MAX = 510000;
ll fact[MAX], fact_inv[MAX];

// 繰り返し二乗法
ll power(ll a, ll b){
  ll res=1;
  while(b>0){
    if(b&1) res=res*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return res;
}

void init(){
  int n = MAX-1;
  fact[0] = 1;
  REP(i, n) fact[i+1]=fact[i]*(i+1)%MOD;
  fact_inv[n]=power(fact[n], MOD-2);
  FOR(i, 0, n) fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
}

ll comb(ll n, ll r){
  return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}
*/

// X^(-1) = X^(p-2) (mod p) (Fermat's little theorem)
//https://atcoder.jp/contests/abc003/submissions/4136198

const ll MAXN = 20000;
ll fact[MAXN+1];
bool fact_init = false;
 
ll pow(ll a, ll b){
  if(b == 0) return 1;
  if(b % 2 == 1) return a * pow(a, b - 1) % MOD;  
  ll d = pow(a, b / 2) % MOD;
  return d * d % MOD;
}

ll comb(ll n, ll k){
  if(!fact_init){
    fact[0] = 1;
    fact[1] = 1;
    
    for(ll i = 2; i <= MAXN; i++){
      fact[i] = fact[i-1] * i;
      fact[i] %= MOD;
    }
    
    fact_init = true;
  }
  
  ll ret = fact[n];
  ret *= pow(fact[k],MOD-2);
  ret %= MOD;
  ret *= pow(fact[n-k],MOD-2);
  ret %= MOD;
  return ret;
  
}

int
main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll r, c, x, y, d, l;
  cin >> r >> c;
  cin >> x >> y;
  cin >> d >> l;
  
  ll ans = 0LL;
  REP(b, 1<<4){
    ll tx = x;
    ll ty = y;

    if((b>>0) & 1) tx--;
    if((b>>1) & 1) ty--;
    if((b>>2) & 1) tx--;
    if((b>>3) & 1) ty--;

    if(tx<0 || ty<0) continue;
    if(tx*ty < d+l) continue;

    ll bsum = 0;
    REP(i, 4) if((b>>i)&1) bsum++;
    
    if(bsum%2 != 0){
      ans += MOD;
      ans -= comb(tx*ty, d+l) * comb(d+l, d) % MOD;
      ans %= MOD;
    }
    else{
      ans += comb(tx*ty, d+l) * comb(d+l, d);
      ans %= MOD;      
    }    
  }

  ans *= (r-x+1) * (c-y+1);
  ans %= MOD;

  cout << ans << endl;
  
  return 0;
}
