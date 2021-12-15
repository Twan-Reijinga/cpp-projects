#include <iostream>
#include <algorithm>
#include <vector>

int getLowestMissingNum(std::vector<int> nums) {
    int nextLowestNum = nums.at(0) + 1;
    for (int i = 1; i<nums.size(); i++) {
        if (nextLowestNum != nums.at(i)) {
            return nextLowestNum;
        }
        nextLowestNum ++;
    }
    return nums.back() + 1;
}

int main() {
    int lengthNumList, newNum, lowestmissingNum;
    std::vector<int> nums;

    std::cout << "How many numbers? ";
    std::cin >> lengthNumList;
    std::cout << "Please enter the numbers "; 
    for(int i = 0; i<lengthNumList; i++) {
        std::cin >> newNum;
        nums.push_back(newNum);
    }
    std::sort(nums.begin(), nums.end());
    lowestmissingNum = getLowestMissingNum(nums);
    std::cout << "The smallest missing number is " << lowestmissingNum << std::endl;

    return 0;
}
