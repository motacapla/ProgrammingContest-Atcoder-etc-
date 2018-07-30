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

int op(int a, int b, int i){
  if(i == 0){
    return a+b;
  }
  else if(i == 1){
    return a-b;
  }
  else if(i == 2){
    return a*b;
  }
  else{
    return a/b;
  }
}

void print_op(int op1){
  if(op1 == 0){
    cout << "+";
  }else if (op1 == 1){
    cout << "-";      
  }else if (op1 == 2){
    cout << "*";      
  }else{
    cout << "/";    
  }
}

int
main(void){  
  string s;
  cin >> s;

  int a, b, c, d;
  a = s[0]-48;
  b = s[1]-48;
  c = s[2]-48;
  d = s[3]-48;  
  
  int op1, op2, op3;

  //cout << op(7, 2, 3) << endl;
  bool f = false;
  REP(i, 4){
    REP(j, 4){
      REP(k, 4){
	int ab = 0, abc = 0, abcd = 0;
	//cout << "i: " << i << " j: " << j << " k: " << k << endl;
	if(b == 0 && i == 3){
	  continue;
	}
	ab = op(a, b, i);	  
	
	if(c == 0 && j == 3){
	  continue;
	}
	abc = op(ab, c, j);

	if(d == 0 && k == 3){
	  continue;
	}
	abcd = op(abc, d, k);
	if(abcd == 7) {
	  op1 = i;
	  op2 = j;
	  op3 = k;
	  f = true;
	  //cout << "Found" << endl;
	}	  	
      }
      if(f) break;      
    }
    if(f) break;
  }

  cout << a;
  print_op(op1);
  cout << b;
  print_op(op2);
  cout << c;
  print_op(op3);
  cout << d << "=7" << endl;
  
  return 0;
}
