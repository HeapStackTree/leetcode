#include <stdio.h>
#include <string>
using namespace std;
int KMP(const string &, const string &);
class Solution {
    public:
        int strStr(string haystack, string needle) {
            return KMP(needle, haystack);
        }
}


int KMP(const string &pattern, const string &text) {
    int n = pattern.size();
    int m = text.size();
    vector<int> next(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
        if (pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    for (int i = 0, j = 0; j < m; j++) {
        while (i > 0 && pattern[i] != text[j]) i = next[i-1];
        if (pattern[i] == text[j]) i++;
        if (i == n) return j - n + 1;
    }
    return -1;
}

int main() {
    Solution s;
    const string hayStack = "sadbutsad";
    const string needle = "sad";
    print("%d", s.strStr(hayStack, needle));
    return 0;
}