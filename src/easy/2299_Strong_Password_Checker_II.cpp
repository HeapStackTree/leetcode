#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < 8) {
            return false;
        }
        bool lower, upper, digit, special;
        lower = upper = digit = special = false;
        char lastchar;
        string specialchars = "!@#$%^&*()-+";
        for (int i = 0; i < n; i++) {
            char ch = password[i];
            if (i > 0 && ch == lastchar) {
                return false;
            }
            if (islower(ch)) {
                lower = true;
            } else if (isupper(ch)) {
                upper = true;
            } else if (isdigit(ch)) {
                digit = true;
            } else if (specialchars.find(ch) != string::npos) {
                special = true;
            }
            lastchar = ch;   
        }
        return lower && upper && digit && special;
    }
};

void testSolution() {
    Solution sol;
    string password = "IloveLe3tcode!";
    cout << sol.strongPasswordCheckerII(password) << "\n";
    password = "Me+You--IsMyDream";
    cout << sol.strongPasswordCheckerII(password) << "\n";
    password = "1aB!";
    cout << sol.strongPasswordCheckerII(password) << "\n";
    password = "a1A!A!A!";
    cout << sol.strongPasswordCheckerII(password) << "\n";
}

int main() {
    testSolution();
    return 0;
}