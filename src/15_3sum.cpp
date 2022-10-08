#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        
        vector<vector<int>> vi;
        // for (int i = 0; i < size - 2; i++) {
        //     for (int j = i + 1; j < size - 1; j++) {
        //         for (int k = j + 1; k < size; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 vi.push_back({i, j, k});
        //             }
        //         }
        //     }
        // }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++) {
            if (nums[i] > 0) return vi;
            int l = i + 1, r = size - 1;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (l < r) {
                int res = nums[i] + nums[l] + nums[r];
                if (res == 0) {
                    vi.push_back({nums[i], nums[l], nums[r]});
                    ++l, --r;
                    while (l < r  && nums[l] == nums[l-1]) ++l;
                    while (l < r && nums[r] == nums[r+1]) --r;
                }
                else if (res > 0) {
                    r--;
                }
                else l++;
            }
        }
        return vi;
    }
};

int main() {
    vector<int> vi{0,0,0,0};
    Solution s = Solution();
    vector<vector<int>> res = s.threeSum(vi);
    for (auto &i: res) {
        for (auto &j :i) {
            printf("%d ", j);
        }
        printf("\n");
    }
}