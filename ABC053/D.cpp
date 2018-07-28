#include <iostream>
#include <algorithm>

using namespace std;

int
main(void){
  int n;
  cin >> n;
  int a[n];
  int max=0;
  for(int i=0; i<n; i++) {cin >> a[i]; if(a[i] > max) max = a[i];}

  //cout << max << endl;
  
  int c[max];
  for(int i=0; i<max; i++) c[i] = 0; 
  
  for(int i=0; i<n; i++){
    c[a[i]-1]++;    
  }

  //for(int i=0; i<max; i++) cout << i << " : " << c[i] << endl; 

  int count = 0;
  for(int i=0; i<max; i++){  
    while(c[i] > 1){
      count++;
      c[i]--;
    }
  }
  if(count%2 != 0) count++;
  cout << n - count << endl;
  
  return 0;
}
