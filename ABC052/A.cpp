#include <iostream>

using namespace std;
using ll = long long;

int
main(void){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a = a*b;
  c = c*d;
  if(a < c){
    cout << c << endl;
  }else{
    cout << a << endl;
  }
  return 0;
}
