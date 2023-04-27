#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int left = dp[i][j + 1] + 1;
                int right = dp[i + 1][j] + 1;
                int left_down = dp[i][j];
                if (word1[i] != word2[j]) {
                    left_down += 1;
                }
                dp[i + 1][j + 1] = min(left_down, min(left, right));
            }
        }
        return dp[n][m];
    }
};