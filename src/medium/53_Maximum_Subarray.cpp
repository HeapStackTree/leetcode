#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], sum = 0;
        for (int i = 0; i < n; i++) {            
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};