#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool check(string& src, string& pattern) {
        int n = src.size(), m = pattern.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (isupper(src[i]) && (src[i] != pattern[j] || j >= m)) {
                return false;
            }
            if (j < m && src[i] == pattern[j]) {
                j++;
            }
        }
        return j == m;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size(), m = pattern.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++) {
            ans[i] = check(queries[i], pattern);
        }
        return ans;
    } 
};