#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& perm, int first, int len){
        if (first == len) {
            ans.push_back(perm);
            return;
        }
        for (int i = first; i < len; i++) {
            swap(perm[first], perm[i]);
            backtrack(ans, perm, first+1, len);
            swap(perm[first], perm[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0, nums.size());
        return ans;
    }
};