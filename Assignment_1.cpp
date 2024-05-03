#include <iostream>

int sumOfDiviser(int input) {
    int sum = 0;
    for (int i = 1; i <= input; i++) {
        if (input % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int numOfTest;
    std::cin >> numOfTest;

    int arr[numOfTest];
    for (int i = 0; i < numOfTest; i++) {
        int input;
        std::cin >> input;
        arr[i] = sumOfDiviser(input);
    }

    for (int i = 0; i < numOfTest; i++) {
        std::cout << arr[i] << std::endl;
    }
}
