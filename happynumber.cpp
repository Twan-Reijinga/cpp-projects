#include <iostream>
#include <cmath>
#include <set>

int getNum() {
    int num;
    if(std::cin >> num) return num;
    throw std::runtime_error("invalid input.");
}

int squareNums(int num) {
    const int base = 10;
    int total = 0;
    while(num > 0) {
        total += pow(num % base, 2);
        num /= base;
    }
    return total;
}

bool isHappy(int num) {
    std::set<int> seenNums;
    while(num > 1 && seenNums.find(num) == seenNums.end()) {
        seenNums.insert(num);
        num = squareNums(num);
    }
    return num == 1;
}

int main() {
    try {
        std::cout << "Which number do you want to test? ";
        int num = getNum();
        if(isHappy(num)) {
            std::cout << num << " is happy!" << std::endl;
        } else {
            std::cout << num << " is unhappy!" << std::endl;
        }
    } catch (std::runtime_error &e) {
        std::cout << e.what();
        return 1;
    }

    return 0;
}
