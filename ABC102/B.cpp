#include <iostream>

using namespace std;

int main(void){
  int n;
  cin >> n;
  
  long long a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  long long max, min;
  max = 0;
  min = 1000000001LL;
  for(int i=0; i<n; i++){
    if(a[i] > max){      
      max = a[i];
    }
    if(a[i] < min){
      min = a[i];
    }
  }

  cout << max-min << endl;
  
  return 0;
}
