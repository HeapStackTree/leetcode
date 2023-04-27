#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<char, int> tcnt, wcnt;
public:
    bool mapEqual() {
        for (const auto& it: tcnt) {
            if (wcnt[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        for (char c: t) {
            ++tcnt[c];
        }
        int l, r, ansL;
        l = r = ansL = 0;
        int minWindow = 10005;
        while (r < s.size()) {
            if (tcnt.find(s[r]) != tcnt.end()) {
                ++wcnt[s[r]];
            }
            while (mapEqual() && l <= r) {
                int windowSize = r  - l + 1;
                if (windowSize < minWindow) {
                    minWindow = windowSize;
                    ansL = l;
                }
                if (tcnt.find(s[l]) != tcnt.end()) {
                    --wcnt[s[l]];
                }
                ++l;
            }
            ++r;
        }
        return minWindow > s.size() ? string() : s.substr(ansL, minWindow);
    }
};