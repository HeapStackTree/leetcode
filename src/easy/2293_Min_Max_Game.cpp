#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> vi;
        for (int i = 0; i < nums.size(); i += 2) {
            if ((i >> 1 & 1) == 0) {
                vi.push_back(min(nums[i], nums[i+1]));
            } else {
                vi.push_back(max(nums[i], nums[i+1]));
            }
        }
        return minMaxGame(vi);
    }
};

class Solution2 {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> newNums(nums.begin(), nums.end());
        while (n != 1) {
            for (int i = 0; i < n / 2; i++) {
                if (i & 1) {
                    newNums[i] = max(newNums[i * 2], newNums[i * 2 + 1]);
                } else {
                    newNums[i] = min(newNums[i * 2], newNums[i * 2 + 1]);
                }
            }
            n >>= 1;
        }
        return newNums[0];
    }
};


void test_solution() {
    vector<int> nums = {70,38,21,22};
    Solution2 sol;
    cout << sol.minMaxGame(nums) << endl;
}

int main() {
    test_solution();
    return 0;
}