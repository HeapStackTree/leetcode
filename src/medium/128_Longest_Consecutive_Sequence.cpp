#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vset;
        for (const int& num: nums) {
            vset.insert(num);
        }
        int maxSize = 0;
        for (const int& num: vset) {
            if (vset.find(num - 1) != vset.end()) {
                continue;
            }
            int current = num;
            int size = 1;
            while (vset.find(current + 1) != vset.end()) {
                current++;
                size++;
            }
            if (size > maxSize) {
                maxSize = size;
            }
        }
        return maxSize;
    }
};