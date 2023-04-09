#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(int start, int target, vector<int>& candidates, vector<int>& combine, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(combine);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (target - candidates[i] >= 0) {
                combine.push_back(candidates[i]);
                dfs(i + 1, target - candidates[i], candidates, combine, ans);
                combine.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combine;
        vector<vector<int>> ans;
        dfs(0, target, candidates, combine, ans);
        return ans;
    }
};