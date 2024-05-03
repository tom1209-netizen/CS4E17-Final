#include <iostream>

std::string encodeString(std::string input) {
    std::string result = "";
    int count = 1;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            result += input[i] + std::to_string(count);
            count = 1;
        }
    }
    return result;
}

int main() {

    std::string input;
    std::getline(std::cin, input);
    std::cout << encodeString(input) << std::endl;
    return 0;
}