#include <iostream>
#include <set>
#include <algorithm>

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
//    sort(a, a + N, greater<int>());  // a[0:N] を大きい順にソート


using namespace std;
using ll = long long;

int
main(void){
  char s[5];
  int n;
  cin >> s >> n;
  int l = 5;
  sort(s, s+l);
  int div = (n-1)/l;
  int p = (n-1)%l;

  cout << s[div] << s[p] << endl; 
  
  return 0;
}
