#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = 0;
        int n = scores.size();
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back({scores[i], ages[i]});
        }
        sort(vec.begin(), vec.end());
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (vec[j].second <= vec[i].second) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += vec[i].first;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};