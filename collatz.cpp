#include <iostream>

int main() {
  int n;
  int countCycles = 0;
  std::cout << "Enter the first number of the sequence: ";
  std::cin >> n;
  std::cout << n << ' ';
  if (n == 1) {
    countCycles ++;
  }
  while (countCycles < 3) {
    if (n % 2) {
      n = n*3+1;
    } else {
      n = n/2;
    }
    std::cout << n << ' ';
    if (n == 1) {
      countCycles ++;
    } 
  }
  std::cout << "...";
  return 0;
}
