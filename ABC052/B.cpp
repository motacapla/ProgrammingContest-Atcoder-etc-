#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int
main(void){
  int n;
  string s;
  cin >> n >> s;

  int c = 0;
  int max = 0;
  for(int i=0; i<n; i++){
    if(s[i] == 'I'){
      c++;
      if(c > max){
	max = c;
      }
    }else if(s[i] == 'D'){
      c--;
    }else{

    }
  }
  cout << max << endl;
  return 0;
}
