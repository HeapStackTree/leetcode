#include <iostream>
#include <vector>
#include <algorithm>
using std::vector, std::cout, std::endl;

class Solution { 
public:

    // int lower_bound(vector<int>& nums, int target) {
    //     int l = 0, r = nums.size();
    //     int mid;
    //     while (l < r) {
    //         mid = l + (r - l) / 2;
    //         if (nums[mid] < target) {
    //             l = mid + 1;
    //         } else {
    //             r = mid;
    //         }
    //     }
    //     return l;
    // }

    // int upper_bound(vector<int> &nums, int target) {
    //     int l = 0, r = nums.size();
    //     int mid;
    //     while (l < r) {
    //         mid = l + (r - l) / 2;
    //         if (nums[mid] <= target) {
    //             l = mid + 1;
    //         } else {
    //             r = mid;
    //         }
    //     }
    //     return l;
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        // int leftIdx = lower_bound(nums, target);
        // int rightIdx = upper_bound(nums, target) - 1;
        auto l = std::lower_bound(nums.begin(), nums.end(), target);
        auto r = std::upper_bound(nums.begin(), nums.end(), target);
        int leftIdx = l - nums.begin();
        int rightIdx = r - nums.begin() - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    vector<int> nums{5, 7, 8, 8, 10};
    int target = 8;
    Solution s;
    for (auto i: s.searchRange(nums, target)) {
        cout << i << ",";
    }
    cout << endl;
}
