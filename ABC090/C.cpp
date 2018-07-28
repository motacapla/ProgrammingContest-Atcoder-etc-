#include <iostream>
#include <algorithm>

using namespace std;

const int e = 1e9;

int
main(void){
  int n, m;
  cin>>n>>m;

  long long count = 0L;
  int one = 1;
  
  if(n == 1 && m == 1){cout << one << endl;}
  else if(n == 1 && m > 1){cout << m-2 << endl;}
  else if(m == 1 && n > 1){cout << n-2 << endl;}
  else{    
    cout << (m-2)*(n-2) << endl;
  }
  return 0;
}


