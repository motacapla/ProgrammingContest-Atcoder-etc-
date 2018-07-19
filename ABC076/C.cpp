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
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }


int
main(void){
  string s, t;
  cin >> s >> t;

  int s_n = s.size();
  int t_n = t.size();
  bool f = false;

  for(int i=s_n-t_n+1; i>=0; --i){
    if(s[i] == t[0] || s[i] == '?'){
      int count = 0;
      while(s[i+count] == t[count] || s[i+count] == '?'){
	count++;
	if(count == t_n) {
	  f = true;
	  break;
	}
      }
      if(f){
	REP(j, count){
	  //cout << "Change:" << i << " " << j << endl;
	  s[i+j] = t[j];
	}
	break;	
      }
    }
  }
  if(f){
    REP(i, s_n){
      if(s[i] == '?') cout << "a";
      else cout << s[i];
    }
    cout << endl;
  }else{
    cout << "UNRESTORABLE" << endl;
  }     
     
  
  /*
  bool f, f2=false, f3=false;

  REP(i, s_n - t_n + 1){
    f=false;
    int count = 0;
    REP(j, t_n){
      if(s[i+j] == t[j]){
	//cout << i << " " << j << endl;
	tmp1 = i+j; // s loc
	tmp2 = j;   // t loc
	f=true;
      }	
    }
    if(f){
      REP(j, t_n){
	cout << count << " " << j << endl;	
	if(s[tmp1+j] != '?' && s[tmp1+j] != t[tmp2+j]){
	  f2=false;
	  break;
	}	
	else{
	  count++;
	  if(count == t_n-1){
	    f2=true;
	  }
	}	
      }
    }
    if(f2){
      if(i == tmp1){
	REP(j, t_n){	
	  cout << i << " " << j << "tmp1+j:" << tmp1+j << " tmp2+j:" << tmp2+j << endl;
	  
	  s[tmp1+j] = t[tmp2+j];
	}
	f2 = false;
	f3 = true;
      }
    }
  }
  
  REP(i, s_n){
    if(s[i] == '?'){
      s[i] = 'a';
    }
  }  
  
  
  if(!f3) cout << "UNRESTORABLE" << endl;
  else cout << s << endl;
  */
    
  return 0;
}
