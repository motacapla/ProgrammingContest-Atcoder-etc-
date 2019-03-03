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

class Solution {
public:
  bool isValid(string S) {
    int a_n = 0, b_n = 0, c_n = 0;
    int i = 0;
    while(i < S.size()){
      //cout << "s[i] " << S[i] << endl;
      if(S[i] == 'a'){
	a_n++;
      }            
      if(S[i] == 'b' && a_n > 0){
	b_n++;
      }            
      if(S[i] == 'c' && b_n > 0 && a_n > 0){
	c_n++;
      }    
      if(c_n > 0){
	string t="";
	bool ok_a = true, ok_b = false, ok_c = false;
	for(int j=0; j<S.size(); j++){                    
	  if(ok_a && S[j] == 'a') {
	    ok_b = true; ok_a = false;
	    continue; 
	  }
	  if(ok_b && S[j] == 'b'){
	    ok_c = true; ok_b = false;
	    continue;
	  }
	  if(ok_c && S[j] == 'c'){
	    ok_c = false;
	    continue;
	  }
	  t += S[j];
	}
	S = t;                
	a_n--, b_n--, c_n--; i=-1;
      }      
      //cout << a_n << ":" << b_n << ":" << c_n << endl;
      //cout << S << endl;
      i++;
    }
    if(S.size() != 0) return false;
    else return true;        
  }
};

int
main(void){  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;

    
  
  return 0;
}
