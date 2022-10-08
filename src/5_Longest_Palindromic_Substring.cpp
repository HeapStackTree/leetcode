#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         if (n < 2) {
//             return s;
//         }
//         int maxLen = 1;
//         int begin = 0;
//         vector<vector<int>> dp(n, vector<int>(n));
//         for (int i = 0; i < n; i++) {
//             dp[i][i] = 1;
//         }
//         for (int L = 2; L <= n; L++) {
//             for (int i = 0; i < n; i++) {
//                 int j = i + L - 1;
//                 if (j >= n) break;
//                 if (s[i] == s[j]) {
//                     if (j - i < 3) {
//                         dp[i][j] = 1;
//                     } else {
//                         dp[i][j] = dp[i + 1][j - 1];
//                     }
//                 }
//                 if (dp[i][j]) {
//                     int subLen = j - i + 1;
//                     if (subLen > maxLen) {
//                         maxLen = subLen;
//                         begin = i;
//                     }
//                 }
//             }
//         }
//         return s.substr(begin, maxLen);
//     }
// };

// class Solution
// {
// public:
//     int expandAroundCenter(const string &s, int left, int right)
//     {

//         while (left >= 0 && right < s.size() && s[left] == s[right])
//         {
//             left--;
//             right++;
//         }
//         return right - left - 1;
//     }

//     string longestPalindrome(string s)
//     {
//         int start = 0, maxlen = 1;
//         for (int i = 0; i < s.size(); ++i)
//         {
//             int len1 = expandAroundCenter(s, i, i);
//             int len2 = expandAroundCenter(s, i, i+1);
//             int maxsublen = max(len1, len2);
//             if (maxsublen > maxlen) {
//                 maxlen = maxsublen;
//                 start = i - (maxlen - 1) / 2;
//             }
//         }
//         return s.substr(start, maxlen);
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) {
            return s;
        }
        vector<int> range(2);
        for (int i = 0; i < s.length(); i++) {
            i = findLongest(s, i, range);
        }
        int maxlen = range[1] - range[0]  + 1;
        return s.substr(range[0], maxlen);
    }
    
    int findLongest(const string &str, int low, vector<int> &range) {
//         查找中间部分
        int high = low;
        while (high < str.length() - 1 && str[high + 1] == str[low]) {
            high++;
        }
//         定位中间部分的最后一个字符
        int ans = high;
//         从中间向左右扩散
        while (low > 0 && high < str.length() - 1 && str[low - 1] == str[high + 1]) {
            low--;
            high++;
        }

        if (high - low > range[1] - range[0]) {
            range[0] = low;
            range[1] = high;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s("cbabcecbasdbacabdad");
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}