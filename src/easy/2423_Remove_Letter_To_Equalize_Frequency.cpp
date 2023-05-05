#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool equalFrequency(string word) {
        vector<char> charCount(26);
        for (char& c: word) {
            charCount[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 0) {
                continue;
            }
            charCount[i]--;
            unordered_set<int> frequency;
            for (int cnt: charCount) {
                if (cnt > 0) {
                    frequency.insert(cnt);
                }
            }
            if (frequency.size() == 1) {
                return true;
            }
            charCount[i]++;
        }
        return false;
    }
};