#include <iostream>
#include <vector>
#include <regex>
void checkInput(const std::string& input) {
    if(!std::regex_match(input, std::regex("^[a-z]*$"))) {
        throw std::runtime_error("invalid input");
    }
}
void compressData(const std::string& uncompressedData, std::vector<int>& runLengths, std::vector<char>& chars) {
    int sameCharCount = 1;
    char prevChar;
    for(int i = 1; i<uncompressedData.size(); i++) {
        prevChar = uncompressedData.at(i-1);
        if (prevChar == uncompressedData.at(i)) {
            sameCharCount++;
        } else {
            chars.push_back(prevChar);
            runLengths.push_back(sameCharCount);
            sameCharCount = 1;
        }
    }
    if (uncompressedData.size()) {
        chars.push_back(uncompressedData.back());
        runLengths.push_back(sameCharCount);
    }
}
int main() {
    std::string uncompressedInput;
    std::vector<int> runLengths;
    std::vector<char> chars;
    std::cout << "Enter the data to be compressed: ";
    std::cin >> uncompressedInput;
    try {
        checkInput(uncompressedInput);
    } catch (std::runtime_error &e) {
        std::cout << "error: " << e.what() << std::endl;
        return 1;
    }
    compressData(uncompressedInput, runLengths, chars);
    std::cout << "The compressed data is: ";
    for(int i = 0; i<runLengths.size(); i++) {
        std::cout << runLengths.at(i) << chars.at(i);
    }
    std::cout << std::endl;
    return 0;
}

