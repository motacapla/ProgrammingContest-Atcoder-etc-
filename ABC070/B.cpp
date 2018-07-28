#include <iostream>

int main(int argc, char* argv[]){
  int A, B, C, D;  
  std::cin >> A;
  std::cin >> B;
  std::cin >> C;
  std::cin >> D;
  
  int tail;
  if(A > C){
    tail = A;
  }
  else{
    tail = C;
  }

  int head;
  if(B > D){
    head = D;
  }
  else{
    head = B;
  }

  if((head - tail) > 0){
    std::cout << (head - tail) << std::endl;
  }else{
    std::cout << 0 << std::endl;
  }
  
  return 0;
}
