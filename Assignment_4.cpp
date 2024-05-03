#include <iostream>

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;

}

bool areDigitsPrime(int num) {
    int digit = num / 10;
    while (digit > 0) {
        if (!(digit == 2 || digit == 3 || digit == 5 || digit == 7)) {
            return false;
        }
        digit /= 10;
    }
    return true;
}

void superPrimeNumber(int n) {
    for (int i = 2; i < n; i++) {
        if (isPrime(i) && areDigitsPrime(i)) {
            std::cout << i << " ";
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    superPrimeNumber(n);

    return 0;
}
