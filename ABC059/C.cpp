#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
using ll = long long;
int
main(void){
  int n;
  cin >> n;
  ll a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  
  ll sum = 0L;
  int count=0;
  int f,p, prev_p;

  sum = a[0];
  if(sum > 0){
    prev_p = 1;
  }else if(sum < 0){
    prev_p = 0;
  }else{
    if(a[1] > 0){
      prev_p = 0;
      sum--;
      count++;
    }else{
      prev_p = 1;
      sum++;
      count++;
    }
  }
  cout << "prevp: " << prev_p << " sum: "<< sum << "count: " << count <<endl;
  for(int i=1; i<n; i++){
    sum = sum + a[i];
    if(sum > 0){
      p = 1; //plus
    }else if(sum < 0){
      p = 0; //minus
    }else{
      if( i < n-1 && a[i+1] > 0){
	prev_p = 0;
	sum--;
	count++;
      }else{      
	p = 1;
	sum++;
	count++;
      }
    }
    
    if(prev_p == p){
      cout << i << " prev_p == p"  << endl;
      if(sum < 0){
	while(sum <= 0){
	  sum++;
	  count++;
	  p = 1;
	}
      }
      else{
	while(sum >= 0){
	  sum--;
	  count++;
	  p = 0;
	}      
      }
    }
    prev_p = p;
    cout << "prevp: " << prev_p << " sum: "<< sum << "count: " << count <<endl;
  }

  cout << count << endl;
  
  return 0;
}
