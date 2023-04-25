#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        auto [minit, maxit] = minmax_element(nums.begin(), nums.end());
        int diff = *maxit - *minit;
        int ans = 1;
        
        for (int d = -diff; d <= diff; d++) {
            vector<int> dp(*maxit + 1, -1);
            for (int num: nums) {
                int prev = num - d;
                if (prev >= *minit && prev <= *maxit && dp[prev] != -1) {
                    dp[num] = max(dp[num], dp[prev] + 1);
                    ans = max(ans, dp[num]);
                }
                dp[num] = max(dp[num], 1);
            }

        }
        return ans;
    }
};
