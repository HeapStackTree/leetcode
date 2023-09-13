#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        int rk = -1;
        unordered_set<char> lookup;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                lookup.erase(s[i - 1]);
            }
            while(rk + 1 < n && !lookup.count(s[rk + 1])) {
                lookup.insert(s[rk + 1]);
                ++rk;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};