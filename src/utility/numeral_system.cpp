#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
int BaseNToDecimal(string &number, int base) {
    int result = 0;
    int power = 1;
    for (auto rit = number.rbegin(); rit != number.rend(); rit++) {
        result += (*rit - '0') * power;
        power *= base;
    }
    return result;
}

void reverse_string(string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

string DemimaltoBaseN(int number, int base) {
    string result;
    while (number) {
        result += to_string(number % base);
        number /= base;
    }
    reverse_string(result);
    return result;
}

int main() {
    int n = 10;
    string n_2 = DemimaltoBaseN(n, 2);
    printf("%s\n", n_2.c_str());
    printf("%d\n", BaseNToDecimal(n_2, 2));
    return 0;
}