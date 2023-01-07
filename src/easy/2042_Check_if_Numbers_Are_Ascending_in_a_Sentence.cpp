#include <stdio.h>

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void bytestoint(string &s, int &i, int &value) {
    value = 0;
    for (; i < s.size(); i++) {
        if (s[i] > '9' || s[i] < '0') break;
        value = (s[i] - '0') + value * 10;
    }
}

class Solution {
public:
    bool areNumbersAscending(string s) {
        int idx, last, value;
        for (idx=0; idx < s.size(); idx++) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                bytestoint(s, idx, last);
                break;
            }
        }
        for (; idx < s.size(); idx++) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                bytestoint(s, idx, value);
                if (value <= last) {
                    return false;
                }
                last = value;
            }
        }
        return true;
    }
};

int main() {
    string s = "1 box has 3 blue 4 red 6 green and 12 yellow m213arbles 111";
    Solution sol;
    cout << sol.areNumbersAscending(s) << endl;
    return 0;
}