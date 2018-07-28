#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
 
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
 
const ll INF = 1e16;
const ll MOD = 1e9 + 7;
 
#define REP(i, j, k) for(ll i = j; i < k; i++)
#define PRINT(i) cout << i << endl;
#define PRINT2(i,j) cout << i << " " << j << endl;
 
int
main(void){
  ll n, k;
  cin >> n >> k;
  if(k == 0){cout << n*n << endl; return 0;}
 
  ll sum = 0L;
  REP(i, k+1, n+1){
    ll q = n/i;
    ll p = n%i;
    ll itmp = i-k;
    if(itmp > 0) sum += q*itmp;    
    if(p >= k) sum += p-k+1;    
    //cout << "r:" << r << " q:" << q << endl;    
    //PRINT2(i, sum);    
  }
  
  PRINT(sum);
  
  return 0;
}
