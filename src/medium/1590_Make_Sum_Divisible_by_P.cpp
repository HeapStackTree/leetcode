#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {

        int n = nums.size();
        vector<int> preSum(n + 1);
        preSum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            preSum[i + 1] = (preSum[i] + nums[i]) % p;
        }
        int x = preSum[n];
        if (x == 0)
        {
            return 0;
        }
        unordered_map<int, int> locMap;
        int ans = n;
        for (int i = 0; i <= n; i++)
        {
            int d1 = preSum[i];
            int d2 = (d1 - x + p) % p;
            locMap[d1] = i;
            auto it = locMap.find(d2);
            if (it != locMap.end())
            {
                ans = ans > i - it->second ? i - it->second : ans;
            }
        }
        return ans < n ? ans : -1;
    }
};

void test_Solution()
{
    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << sol.minSubarray(nums, p) << endl;
    nums = {6, 3, 5, 2};
    p = 9;
    cout << sol.minSubarray(nums, p) << endl;
    nums = {1, 2, 3};
    p = 7;
    cout << sol.minSubarray(nums, p) << endl;
    nums = {1, 2, 3};
    p = 3;
    cout << sol.minSubarray(nums, p) << endl;
}
int main()
{
    test_Solution();
    return 0;
}