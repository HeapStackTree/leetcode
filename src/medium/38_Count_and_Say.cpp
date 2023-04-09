#include <string>
using namespace std;
class Solution1 {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string pre = countAndSay(n - 1);
        char ch = pre[0];
        int cnt = 1;
        string ans;
        for (int i = 1; i < pre.size(); i++) {
            if (pre[i] != ch) {
                ans = ans + to_string(cnt) + ch;
                ch = pre[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans = ans + to_string(cnt) + ch;
        return ans;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string curr = "";
            int start = 0;
            int pos = 0;

            while (pos < prev.size()) {
                while (pos < prev.size() && prev[pos] == prev[start]) {
                    pos++;
                }
                curr += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = curr;
        }
        
        return prev;
    }
};
