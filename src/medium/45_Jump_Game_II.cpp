#include <vector>
#include <algorithm>
using namespace std;

class Solutio1 {
public:
    int jump(vector<int>& nums) {
        int pos = nums.size() - 1;
        int steps = 0;
        while (pos > 0) {
            for (int i = 0; i < pos; i++) {
                if (i + nums[i] >= pos) {
                    pos = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; i++) {
            maxPos = max(i + nums[i], maxPos);
            if (i == end) {
                end = maxPos;
                ++step;
            }
        }
        return step;
    }
};