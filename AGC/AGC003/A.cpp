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

map<char, int> mp;

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  REP(i,s.size()) mp[s[i]]++;

  if(mp['N'] > 0 && mp['S'] > 0 && mp['E'] > 0 && mp['W'] > 0) cout << "Yes" << endl;
  else if(mp['N']>0 && mp['S']>0){
    if(mp['E']>0 || mp['W']>0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  else if(mp['E']>0 && mp['W']>0){
    if(mp['N']>0 || mp['S']>0) cout << "No" << endl;
    else cout << "Yes" << endl;    
  }else{
    cout << "No" << endl;
  }
    
  return 0;
}


/*
yes 
文字n,s or e,w
文字n,s,e,w

 */
