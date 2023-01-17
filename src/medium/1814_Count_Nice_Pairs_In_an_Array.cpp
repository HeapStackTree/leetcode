#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int rev(int x) {
    int res = 0;
    while (x != 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<int, int> h;
        for (int i: nums) {
            int r = rev(i);
            res += h[i - r];
            h[i - r]++;
        }
        int ans = res % ((int)1e9 + 7);
        return ans;
    }
};

void testSolution() {
    Solution sol;
    vector<int> nums = {42, 11, 1, 97};
    cout << sol.countNicePairs(nums) << endl;
    nums = {13, 10, 35, 24, 76};
    cout << sol.countNicePairs(nums) << endl;
}

int main() {
    testSolution();
    return 0;
}