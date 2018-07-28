#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
using ll = long long;

const ll e = 1e9 + 7;

int s[10000];

int
main(void){
  int n;
  cin >> n;

  for(int i=2; i<=n; i++){
    int c = i;
    for(int j=2; j<=i; j++){
      while(c%j == 0){
	s[j]++;
	c /= j;
      }
    }
  }

  //for(int i=0; i<n; i++) cout << s[i] << endl;

  ll sum = 1;
  for(int i=2; i<=n; i++) {
    sum = (sum * (s[i] + 1LL)) % e;
  }
  
  cout << sum << endl;
  
  
  return 0;
}

