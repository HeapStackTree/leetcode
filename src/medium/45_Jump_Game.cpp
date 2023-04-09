#include <vector>
using namespace std;

class Solution {
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