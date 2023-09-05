#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int majority = 0, cnt = 0;
        for (int i: nums) {
            ++count[i];
            if (count[i] > cnt) {
                majority = i;
                cnt = count[i];
            }
        }
        return majority;
    }
};