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

bool debug = true;
ll nl, nm;

int res = 0;
int size = 0;
map<char, int> u, w;
int n, k;
string s = "";
string t = "";

bool is_ok(int k){
  int r = 0;
  for(char i='a'; i<='z'; i++) r += min(u[i],w[i]);
  return size-r <= k;
}

int
main(void){  
  cin.tie(0);
  ios::sync_with_stdio(false);


  cin >> n >> k;
  cin >> s;

  vector<char> v, t;
  REP(i, n) v.push_back(s[i]);
  sort(v.begin(), v.end(), greater<char>());

  while(res < s.size()){
    ROF(i, v.size()-1, 0){
      if(s[res] != v[i]){
	u[s[res]]++;
	w[v[i]]++;
	size++;
	k--;
	if(is_ok(k)){
	  res++;
	  t.push_back(v[i]);
	  v.erase(v.begin()+i);
	  break;
	}
	else{
	  size--;
	  u[s[res]]--;
	  w[v[i]]--;
	  k++;
	}
      }
      else{
	if(is_ok(k)){
	  res++;
	  t.push_back(v[i]);
	  v.erase(v.begin()+i);
	  break;
	}
      }
    }
  }

  REP(i, t.size()) cout << t[i];
  cout << endl;
  
  return 0;
}
