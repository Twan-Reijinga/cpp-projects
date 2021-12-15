#include <iostream>

int main() {
    char symbol;
    double number1, number2, answer;
    
    while (symbol != 'q') {
        std::cout << "Enter the expression: ";
        std::cin >> symbol;
        if (symbol != 'q') {
            std::cin >> number1 >> number2;
            switch (symbol) {
                case '+':
                    answer = number1 + number2;
                    break;
                case '-':
                    answer = number1 - number2;
                    break;
                case '*':
                    answer = number1 * number2;
                    break;
                case '/':
                    answer = number1 / number2;
                    break;
            }
            std::cout << number1 << ' ' << symbol << ' ' << number2 << " = " << answer << std::endl;
        }
    }
    return 0;
}
