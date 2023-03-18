#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin();
        int n = nums.size();
        vector<int> cnt(2 * n);
        cnt[n] = 1;
        for (int i = pos - 1, x = n; i >= 0; --i) { // 从 pos-1 开始累加 x
            x += nums[i] < k ? 1 : -1;
            ++cnt[x];
        }

        int ans = cnt[n] + cnt[n - 1];
        for (int i = pos + 1, x = n; i < n; ++i) { // 从 pos+1 开始累加 x
            x += nums[i] > k ? 1 : -1;
            ans += cnt[x] + cnt[x - 1];
        }
        return ans;
    }
};