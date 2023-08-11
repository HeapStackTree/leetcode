#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<int> count(26), ans;
        if (sLen < pLen) {
            return ans;
        }
        for (int i = 0; i < pLen; i++) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }
        int differ = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                ++differ;
            }
        }
        if (differ == 0) {
            ans.push_back(0);
        }
        for (int i = 0; i < sLen - pLen; i++) {
            if (count[s[i] - 'a'] == 1) {
                --differ;
            } else if (count[s[i] - 'a'] == 0) {
                ++differ;
            }
            --count[s[i] - 'a'];
            
            if (count[s[i + pLen] - 'a'] == -1) {
                --differ;
            } else if (count[s[i + pLen] - 'a'] == 0) {
                ++differ;
            }
            ++count[s[i + pLen] - 'a'];
            if (differ == 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<int> ans;
        if (sLen < pLen) { 
            return ans;
        }
        vector<int> countS(26), countP(26);
        for (int i = 0; i < pLen; i++) {
            ++countS[s[i] - 'a'];
            ++countP[p[i] - 'a'];
        }
        if (countS == countP) {
            ans.push_back(0);
        }
        for (int i = 0; i < sLen - pLen; i++) {
            --countS[s[i] - 'a'];
            ++countS[s[i + pLen] - 'a'];
            if (countS == countP) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};