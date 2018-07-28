#include <iostream>
#include <algorithm>

using namespace std;



int
main(void){
  int a, b;
  cin >> a >> b;

  int count = 0;
  for(int i=a; i<=b; i++){
    string s = to_string(i);
    if(s[0] == s[4] && s[1] == s[3]){
      count++;
    }
  }

  cout << count << endl;
  
  return 0;
}
