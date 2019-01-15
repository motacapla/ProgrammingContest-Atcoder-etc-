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

bool debug = false;

double round(double s, int l){
  double ret;
  l--;
  ret = s * pow(10.0, l);
  ret = (double)(int)(ret+0.5);

  return ret * pow(10.0, -l);
}

int
main(void){  
  ios_base::sync_with_stdio(false);

  double Deg, Dis;
  cin >> Deg >> Dis;

  string Dir="", W="";

  Dis /= 60;
  if(debug) printf("%10f\n", Dis);

  Dis = round(Dis, 2);

  if(debug) printf("%10f\n", Dis);  

  Dis = (floor((int)(Dis*100))/100);

  if(debug) printf("%10f\n", Dis);    
  
  if(0.0 <= Dis && Dis <= 0.2){
    W += "0";
  }
  else if(0.3 <= Dis && Dis <= 1.5){
    W += "1";
  }
  else if(1.6 <= Dis && Dis <= 3.3){
    W += "2";
  }
  else if(3.4 <= Dis && Dis <= 5.4){
    W += "3";
  }
  else if(5.5 <= Dis && Dis <= 7.9){
    W += "4";
  }
  else if(8.0 <= Dis && Dis <= 10.7){
    W += "5";
  }
  else if(10.8 <= Dis && Dis <= 13.8){
    W += "6";
  }
  else if(13.9 <= Dis && Dis <= 17.1){
    W += "7";
  }
  else if(17.2 <= Dis && Dis <= 20.7){
    W += "8";    
  }
  else if(20.8 <= Dis && Dis <= 24.4){
    W += "9";
  }
  else if(24.5 <= Dis && Dis <= 28.4){
    W += "10";
  }
  else if(28.5 <= Dis && Dis <= 32.6){
    W += "11";
  }
  else if(32.7 <= Dis){
    W += "12";
  }
	  
  Deg = Deg/10;
  if(Dis <= 0.2) {Dir += "C"; cout << Dir << " " << W << endl; return 0;}
  else if(11.25 <= Deg && Deg < 33.75){    
    Dir += "NNE";
  }
  else if(33.75 <= Deg && Deg < 56.25){
    Dir += "NE";
  }
  else if(56.25 <= Deg && Deg < 78.75){
    Dir += "ENE";
  }
  else if(78.75 <= Deg && Deg < 101.25){
    Dir += "E";
  }
  else if(101.25 <= Deg && Deg < 123.75){
    Dir += "ESE";
  }
  else if(123.75 <= Deg && Deg < 146.25){
    Dir += "SE";
  }
  else if(146.25 <= Deg && Deg < 168.75){
    Dir += "SSE";
  }
  else if(168.75 <= Deg && Deg < 191.25){
    Dir += "S";
  }
  else if(191.25 <= Deg && Deg < 213.75){
    Dir += "SSW";
  }
  else if(213.75 <= Deg && Deg < 236.25){
    Dir += "SW";    
  }
  else if(236.25 <= Deg && Deg < 258.75){
    Dir += "WSW";
  }
  else if(258.75 <= Deg && Deg < 281.25){
    Dir += "W";
  }
  else if(281.25 <= Deg && Deg < 303.75){
    Dir += "WNW";
  }
  else if(303.75 <= Deg && Deg < 326.25){
    Dir += "NW";
  }
  else if(326.25 <= Deg && Deg < 348.75){
    Dir += "NNW";
  }
  else{
    Dir += "N";
  }

  cout << Dir << " " << W << endl;
  
  return 0;
}
