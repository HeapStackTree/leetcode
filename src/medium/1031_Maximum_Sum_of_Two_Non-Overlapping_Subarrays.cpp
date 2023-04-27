#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int slidingWindow(vector<int>& nums, int firstLen, int secondLen) {
        int suml = accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int maxSuml = suml;
        int sumr = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int res = maxSuml + sumr;
        for (int i = firstLen + secondLen, j = firstLen; i < nums.size(); ++i, ++j) {
            suml += nums[j] - nums[j - firstLen];
            maxSuml = max(maxSuml, suml);
            sumr += nums[i] - nums[i - secondLen];
            res = max(res, maxSuml + sumr);
        }
        return res;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(slidingWindow(nums, firstLen, secondLen), slidingWindow(nums, secondLen, firstLen));
    }
};