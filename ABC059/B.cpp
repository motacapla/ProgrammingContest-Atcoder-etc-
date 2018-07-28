#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <climits>
#include <stdlib.h>

using namespace std;
using ll = long long;

int
main(void){
  char a[100000], b[100000];
  int i=0;
  char c;

  while( (c = getchar()) != '\n' ){
    a[i] = c;
    i++;
    //cout << a[i-1] << endl;
  }

  i=0;
  while( (c = getchar()) != '\n' ){
    b[i] = c;
    i++;
  }
  
  int A, B;
  char d[1];
  for(int i=0; i<10; i++){
    d[0] = a[i];
    cout << d[0] << endl;
    A = atoi(d);
    d[0] = b[i];
    cout << d[0] << endl;    
    B = atoi(d);
    cout << "a:" <<  A << "b:" << B << endl;
  }
  /*
  if(a>b){
    cout << "GREATER" << endl;
  }else if(a < b){
    cout << "LESS" << endl;
  }else{
    cout << "EQUAL" << endl;
  }
  */
  return 0;
}
