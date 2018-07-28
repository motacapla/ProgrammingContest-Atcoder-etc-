#include <iostream>

using namespace std;
using ll = long long;

int
main(void){
  int n;
  ll a, b;
  cin >> n >> a >> b;

  ll x[n];
  for(int i=0; i<n; i++) cin >> x[i];
  
  ll sum;
  sum = 0L;
  for(int i=0; i<n-1; i++){
    ll diff = x[i+1] - x[i];
    if( (diff * a) > b ){
      sum = sum + b;
    }else{
      sum = sum + (diff * a);
    }
    //cout << n << " "<< diff * a <<" " << b << " " << sum << endl;    
  }
  cout << sum << endl;
  return 0;
}
