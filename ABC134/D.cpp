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

int bit[20000010];

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];  
  vector<ll> ans;
  
  ROF(i,n-1,0){
    //cerr << i << endl;
    //bit on
    if(a[i] == 1){
      if(bit[i+1]%2==0){
	bit[i+1]++;      
	ans.push_back(i+1);
	vector<ll> primes = divisor((ll)(i+1));
	//cerr << "num: " << i+1 << endl;
	for(ll j=0; j<primes.size(); j++){
	  //cerr << "j: " << j << " elm: " << primes[j] << endl;
	  bit[primes[j]]++;
	}
      }
    }else {
      //奇数
      if(bit[i+1]%2!=0){
	bit[i+1]++;
	ans.push_back(i+1);
	vector<ll> primes = divisor((ll)(i+1));
	for(ll j=0; j<primes.size(); j++){
	  //cerr << "j: " << j << " elm: " << primes[j] << endl;
	  bit[primes[j]]++;
	}	
      }
    }
    /*
    for(int j=0; j<=n; j++){
      cerr << bit[j] << " ";
    }
    cerr << endl;
    */
  }
  cout << ans.size() << endl;
  for(auto &e: ans) cout << e << endl;
  return 0;
}
