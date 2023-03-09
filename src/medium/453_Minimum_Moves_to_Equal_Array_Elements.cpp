#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int min_elm = *min_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            res += nums[i] - min_elm;
        }
        return res;
    }
};