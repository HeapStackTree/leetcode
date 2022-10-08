#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        // return s1.size() == s2.size() && KMP(s1 + s1, s2);
        return KMP(s1, s2);
    }
    bool KMP(string s1, string s2) {
        vector<int> next = getNextArray(s2);
        int i1 = 0;
        int i2 = 0;
        while (i1 < s1.size() && i2 < s2.size()) {
            if (s1[i1] == s2[i2]) {
                i1++;
                i2++;
            }
            else if (i2 != 0) {
                i2 = next[i2];
            } else {
                i1++;
            }
        }
        // return i2 == s2.size()? i1 - i2 : -1;
        return i2 == s2.size() ? true : false;

    }
    vector<int> getNextArray(string &s) {
        if (s.size() == 1) return {-1};
        vector<int> next(s.size());
        next[0] = -1;
        next[1] = 0;
        int i = 2;
        int cn = 0;
        while (i < next.size()) {
            if (s[i - 1] == s[cn]) {
                next[i++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[i++] = 0;
            }
        }
        return next;
    }   
};

int main() {
    // string s1 = "abcdefgh";
    // string s2 =  "fghabcde";
    string s1 = "afweagacasdfee";
    string s2 = "acasd";
    Solution s;
    // if (s1.size() == s2.size() == 0 )
    //     cout << (s1.size() == s2.size()) << endl;
    // cout <<  << endl;
    cout << s.isFlipedString(s1, s2) << endl;
    return 0;
}