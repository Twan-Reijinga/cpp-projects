#include <iostream>
#include <cmath>

double getInput() {
    double input;
    if (std::cin >> input) {
        return input;
    }
    throw std::runtime_error("Malformed user input");
}

double getDiscriminant(double a, double b, double c) {
    return b*b-4*a*c;
}

double getQuadraticFormula(double a, double b, double d, int SolutionNr) {
    if (SolutionNr == 1) {
        return (-b+sqrt(d))/(2*a);
    } else {
        return (-b-sqrt(d))/(2*a);
    }
}

int main() {
    double a, b, c, d; 
    try {
        std::cout << "Please enter the values of a, b, and c: ";
        a = getInput();
        if (a == 0) {
            throw std::runtime_error("a must not be zero");
        }
        b = getInput();
        c = getInput();
        d = getDiscriminant(a, b, c);
    } catch (std::runtime_error &e){
        std::cout << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    if (d > 0) {
        std::cout << "There are 2 solutions." << std::endl 
        << "The solutions are: " << getQuadraticFormula(a,b,d,1) 
        << " and " << getQuadraticFormula(a,b,d,2);
    } else if (d == 0) {
        std::cout << "There is 1 solution." << std::endl 
        << "The solution is: " << getQuadraticFormula(a,b,d,1);
    } else {
        std::cout << "There is no solution.";
    }
    return 0;
}
