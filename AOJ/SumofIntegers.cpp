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

int ans;

void solve(int n, int s, int m){
  if(n == 0 && s == 0) {
    ans++;
    return;
  }
  if(n > 0){
    for(int i=m; i<10; i++){
      solve(n-1, s-i, i+1);
    }
  }
}


int
main(void){  
  ios_base::sync_with_stdio(false);
  int x, y;
  while(true){
    ans = 0;
    cin >> x >> y;
    if(x == y && x == 0) break; 
    solve(x, y, 0);
    
    cout << ans << endl;    
  }
    
  
  return 0;
}
