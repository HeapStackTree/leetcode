#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int GCD(int, int);
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++) {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i) {
                if (occured[j]) {
                    if (subGcd == 0) {
                        subGcd = j;
                    } else {
                        subGcd = GCD(subGcd, j);
                    }
                    if (subGcd == i) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int GCD(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void test_solution() {
    Solution sol;
    vector<int> nums = {5, 15, 40, 5, 6};
    cout << sol.countDifferentSubsequenceGCDs(nums) << endl;
}

int main() {
    test_solution();
    return 0;
}