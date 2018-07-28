#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const ll mod = 1e9+7;

ll factorial(int a){
  ll val = a;
  for(int i=a-1; i>0; --i){
    val = val * i;
    //cout << i << ":" << val << endl;
  }
  return val;
}

int
main(void){
  ll w, h;
  cin >> w >> h;

  ll wll = factorial(w-1);
  ll hll = factorial(h-1);  
  ll whll = factorial(w+h-2);
  
  cout << whll/(wll*hll) << endl;
  
}
