#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int clsum = 5000, lastsum, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n - 1; i++) {
            int l = 0, r = n - 1;
            while (l < i && r > i) {
                lastsum = nums[i] + nums[l] + nums[r];
                if (lastsum == target) return lastsum;
                if (abs(lastsum - target) < abs(clsum - target)) clsum = lastsum;
                if (lastsum > target) r--;
                else l++;
            }
        }
        return clsum;
    }
};
int main() {
    vector<int> nums{4,0,5,-5,3,3,0,-4,-5};
    int target = -2;
    Solution s;
    cout << s.threeSumClosest(nums, target) << endl;
    return 0;
}