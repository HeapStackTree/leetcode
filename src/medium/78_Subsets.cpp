#include <vector>
using namespace std;
class Solution {
public:
    void dfs(int cur, vector<int>& nums, vector<int>& comb, vector<vector<int>>& ans) {
        if (cur == nums.size()) {
            ans.push_back(comb);
            return;
        }
        comb.push_back(nums[cur]);
        dfs(cur + 1, nums, comb, ans);
        comb.pop_back();
        dfs(cur + 1, nums, comb, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> comb;
        vector<vector<int>> ans;
        dfs(0, nums, comb, ans);
        return ans;
    }
};