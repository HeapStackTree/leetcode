#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        auto matches = [&] (int i, int j) {
            if (i == 0) return false;
            if (p[j - 1] == '.') return true;
            return s[i - 1] == p[j - 1];
        };
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j-2];
                    if (matches(i, j-1)) {
                        dp[i][j] |= dp[i-1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    };
};
int main() {
    string s1 = "ab";

    string s2 = ".*b";
    Solution s;
    bool ans = s.isMatch(s1, s2);
    cout<< ans << endl;
    return 0;
}