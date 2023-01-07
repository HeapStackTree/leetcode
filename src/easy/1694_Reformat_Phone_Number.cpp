#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        string res;
        for (char ch: number) {
            if (ch >= '0' && ch <= '9') {
                digits += ch;
            }
        }
        for (int i = 0; i < digits.size(); i += 3) {
            if (i != 0) res += "-";
            if (i + 4 == digits.size()) {
                res += digits.substr(i, 2) + "-" + digits.substr(i+2, 2);
                i += 4;
            }
            res += digits.substr(i, 3);
        }
        return res;
    }
};

int main() {
    string number = "123 4-5678";
    Solution s;

    cout << s.reformatNumber(number) << endl;
    return 0;
}