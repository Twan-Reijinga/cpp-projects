#include <iostream>
#include <string> 

int getInput() {
    signed int input;
    if (std::cin >> input && input > 0) {
        return input;
    }
    throw std::runtime_error("invalid input.");
}

std::string towerOfHanoi(int H, char source, char target, char helper) {
    if(H == 1) {
        return "Move disk " + std::to_string(H) + " from " + source + " to " + target + ".\n";
    }

    return towerOfHanoi(H-1, source, helper, target) 
    + "Move disk " + std::to_string(H) + " from " + source + " to " + target + ".\n" 
    + towerOfHanoi(H-1, helper, target, source);
}

int main(){
    char source = 'A', target = 'C', helper = 'B';
    
    try {
        std::cout << "How many disks should the tower consist of? ";
        int H = getInput();
        std::cout << towerOfHanoi(H, source, target, helper);
    } catch (std::runtime_error &e) {
        std::cout << e.what();
        return 1;
    }
    
    return 0;
}
