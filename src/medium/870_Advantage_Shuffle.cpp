#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n);
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(nums1.begin(), nums1.end());
        sort(ids.begin(), ids.end(), [&](int i, int j) {return nums2[i] < nums2[j];});
        int left = 0, right = n - 1;
        for (int x: nums1) {
            ans[x > nums2[ids[left]] ? ids[left++] : ids[right--]] = x;
        }
        return ans;
    }
};