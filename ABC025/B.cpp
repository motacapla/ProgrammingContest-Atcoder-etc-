#include <iostream>
#include <set>
#include <algorithm>

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
//    sort(a, a + N, greater<int>());  // a[0:N] を大きい順にソート


using namespace std;
using ll = long long;

int
main(void){
  int n, a, b;
  cin >> n >> a >> b;
  string s[n];
  int d[n];
  int sum = 0;
  REP(i,n) {
    cin >>s[i] >> d[i];
    if(s[i] == "West"){
      if(d[i] < a){
	sum = sum - a;
      }
      else if(d[i] > b){
	sum = sum - b;	
      }
      else{
	sum = sum - d[i];
      }
    }
    else{
      if(d[i] < a){
	sum = sum + a;
      }
      else if(d[i] > b){
	sum = sum + b;	
      }
      else{
	sum = sum + d[i];
      }
    }
  }
  if(sum > 0){
    cout << "East " << sum << endl;
  }else if(sum < 0){
    cout << "West " << abs(sum) << endl;
  }else{
    cout << 0 << endl;
  }
  return 0;
}
