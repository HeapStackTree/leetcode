#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0 || n == 1) {
            return to_string(n);
        }
        string ans;
        while (n != 0) {
            int remainder = n & 1;
            ans.push_back('0' + remainder);
            n -= remainder;
            n /= -2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};