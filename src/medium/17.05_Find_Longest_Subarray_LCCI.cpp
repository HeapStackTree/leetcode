#include <vector>
#include <string>
#include <unordered_map>
#include <ctype.h>
using namespace std;
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        unordered_map<int, int> indices;
        indices[0] = -1;
        int sum = 0;
        int start = -1;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            if (isalpha(array[i][0])) {
                sum++;
            } else {
                sum--;
            }
            auto it = indices.find(sum);
            if (it != indices.end()) {
                int length = i - it->second;
                if (length > maxLength) {
                    maxLength = length;
                    start = it->second + 1;
                }
            } else {
              indices[sum] = i;
            }
        }   
        if (maxLength == 0) {
            return {};
        }
        return vector<string>(array.begin() + start, array.begin()+start+maxLength);
    }
};

