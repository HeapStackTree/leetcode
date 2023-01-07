#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;



class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int rsum = 0, lsum = 0;
        int left = -1, right = 0;
        for (int i=0; i<n; i++) {
            rsum += nums[i];
        }
        int ans = n + 1;

        for (;left < n; left++) {

            if (left != -1) {
                lsum += nums[left];
            }

            while (lsum + rsum > x && right < n)  {
                rsum -= nums[right++];
            }

            if (left >= right) return -1;

            if (lsum + rsum == x) {
                ans = min(ans, left + 1 + n - right);
            }
        }
        
        return ans > n ? -1 : ans;
    }
};


int main() {
    vector<int> nums{1, 2, 3, 4};
    int x = 10;
    Solution s;
    cout << s.minOperations(nums, x) << endl;
    return 0;
}