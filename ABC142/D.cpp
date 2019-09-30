// 素因数分解したら互いに素な要素だけ抽出できる
// for文はllにする

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)

using namespace std;
using ll = long long;
const int MOD=1e9+7;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

ll gcd(ll a, ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll a, b; cin >> a >> b;
  ll val = gcd(a,b);

  ll ans = 1;
  for(ll i=2; i*i<=val; i++){
    if(val%i == 0) {
      while(val%i == 0) val/=i;
      ans++;
    }
  }
  if(val != 1) ans++;
  cout << ans << "\n";
  return 0;
}