#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(26);
            int maxFreq = 1;
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                maxFreq = max(cnt[s[j] - 'a'], maxFreq);
                int minFreq = s.size();
                for (int k = 0; k < 26; k ++ ) {
                    if (cnt[k] > 0) {
                        minFreq = min(cnt[k], minFreq);
                    }
            }
            res += maxFreq - minFreq;
            }
            
        }
        return res;
    }
};