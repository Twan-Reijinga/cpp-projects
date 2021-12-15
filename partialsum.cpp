#include <iostream>
#include <vector>

int main() {
    int n, x, partialSum = 0;
    std::vector<int> partialSums;
    std::cout << "Summing up 1 to n, please enter n: ";
    std::cin >> n;
    for(int i = 0; i<n; i++) {
        partialSum += i+1;
        partialSums.push_back(partialSum);
    }
    std::cout << "Which partial sum (1+...+x) would you like to know? Please enter x<=n : ";
    std::cin >> x;
    for(int i = 0; i<x-1; i++) {
        std::cout << i+1 << '+';
    }
    std::cout << x << " = "<< partialSums.at(x-1);
    std::cout << "\nThe entire sequence of partial sums up to " << n << " is: ";
    for (const int& i : partialSums) {
        std::cout << i << ' ';
    }

    return 0;
}
