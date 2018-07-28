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
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n);
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

int
main(void){
  string s;
  cin >> s;
  
  auto num = atoi(s.c_str());

  ll ans = 0;
  ll n = s.size();
  ll i_s[n];

  REP(i, n) i_s[i] = s[i] - '0';

  //bit演算の用途が違う!
  //あるインデックスの数字をpush_backするのではなく, 数値自体は独自に作る
  //bit演算は数字らのセパレートに用いる
  REP(i, (1 << (n-1))){
    ll left=0, right=0;
    cout << "i:" << i << endl;
    REP(j, n){
      right = right * 10 + i_s[j];
      cout << "right: " << right << " ";          
      if(i & (1 << j)){
	left += right;
	cout << "left: " << left << endl;	
	right = 0;
      }    
    }
    cout << endl;
    left += right;
    ans += left;
    cout << "ans: " << ans << endl;    
  }

  cout << ans << endl;
  
  return 0;
}


// ベクトルにpush_backするのではなく, 直接right, leftを作ればよかった
// 下の例でもright = right * 10 + i_s[i]でよい

  /*  
  REP(bit, (1<<n)){
    vector<ll> l;
    vector<ll> r;
    REP(i, n){
      if (bit & (1<<i)) { // i が bit に入るかどうか
	l.push_back(i_s[i]);
      }
      else{
	r.push_back(i_s[i]);
      }
    }

    ll l_v=0L, r_v=0L;

    REP(i, l.size()){
      l_v += l[i]*pow(10,l.size()-1-i);
    }
    REP(i, r.size()){
      r_v += r[i]*pow(10,r.size()-1-i);
    }
    
    cout << l_v + r_v << endl;
    ans += l_v + r_v;
  }

  cout << ans - num << endl;
  */
