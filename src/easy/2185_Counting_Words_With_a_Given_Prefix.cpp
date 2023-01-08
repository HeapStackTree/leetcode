#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool hasPrefix(string& word, string& pref) {
        int wsize = word.size();
        int prefsize = pref.size();
        if (prefsize > wsize) return false;
        for (int i = 0; i < prefsize; i++) {
            if (word[i] != pref[i]) return false;
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (string &s: words) {
            if (hasPrefix(s, pref)) {
                cnt++;   
            }
        }
        return cnt;
    }
};

int main() {
    vector<string> words{"pay","attention","practice","attend"};
    string pref = "at";
    Solution s;
    cout << s.prefixCount(words, pref) << endl;
}