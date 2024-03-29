#include <string>
using namespace std;

class Solution {
public:
    bool judge(const string& text, int l1, int l2, int len) {
        while (len --) {
            if (text[l1] != text[l2]) {
                return false;
            }
            ++l1;
            ++l2;
        }
        return true;
    }
    int longestDecomposition(string text) {
        int n = text.size();
        int ans = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int len = 1;
            while (l + len - 1 < r - len + 1) {
                if (judge(text, l, r - len + 1, len)) {
                    ans += 2;
                    break;
                }
                len++;
            }
            if (l + len - 1 >= r - len + 1) {
                ans++;
            }
            l += len;
            r -= len;
        }
        return ans;
    }
};