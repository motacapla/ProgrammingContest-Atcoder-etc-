#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(void){
  int n;
  cin >> n;
  
  vector<long long> a = vector<long long>(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  long long temp[n];
  for(int i=0; i<n; i++){
    a[i] = a[i] - i - 1;
  }
  sort(a.begin(), a.end());

  long long median1, median2;
  if(n%2 == 0){
    median1 = a[n/2-1];    
    median2 = a[n/2];
    median1 = min(median1, median2);
  }
  else{
    median1 = a[n/2];
  }
  long long sum = 0LL;
  for(int i=0; i<n; i++){
    sum = sum + abs(a[i] - median1);
  }
  cout << sum << endl;
  
  return 0;
}
