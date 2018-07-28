#include <iostream>

int main(int argc, char* argv[]){
  std::string N;
  
  std::cin >> N;
  if(N[0] == N[2]){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }
  return 0;
}
