#include <iostream>
#include <algorithm>

using namespace std;

int
main(void){
  int x, y;
  cin >> x >> y;

  if(x < y){
    cout << "Better" << endl;
  }
  else{
    cout << "Worse" << endl;
  }
  return 0;
}
