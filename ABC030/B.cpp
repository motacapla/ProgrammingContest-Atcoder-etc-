#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int
main(void){
  double n, m;
  cin >> n >> m;

  double a = m * 6;
  double b = (n * 30) + (m / 2);

  if(a > b){
    a = a - b;
  }
  else{
    a = b - a;     
  }
  a = fmod(a, 360);
  //cout << a << endl;
  
  if ( a > 180 ){
      cout << 360 - a << endl;
  }  
  else{
    cout << a << endl;
  }
  return 0;
}
