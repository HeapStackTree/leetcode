#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> preSum(n + 1);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = upper_bound(preSum.begin(), preSum.end(), queries[i]) - preSum.begin() - 1;
        }
        return ans;
    }
};