#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (ans.empty() || L > ans.back()[1]) {
                ans.push_back({L, R});
            } else if (R > ans.back()[1]) {
                ans.back()[1] = R;
            }
        }
        return ans;
    }
};