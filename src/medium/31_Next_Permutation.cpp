#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = nums.size() - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) {
            left--;
        }
        
        if (left >= 0) {
            for (int j = nums.size() - 1; j > left; j--) {
                if (nums[j] > nums[left]) {
                    swap(nums[left], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + left + 1, nums.end());
    } 
};