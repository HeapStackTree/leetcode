#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // min()

using namespace std;
string trim_space(string str) {
    int first = 0, last = str.size();
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            first = i;
            break;
        }
    }
    for (int j = last - 1; j >= 0; j--) {
        if (str[j] == ' ') {
            last = j + 1;
            break;
        }
    }
    return str.substr(first, last - first);
}

vector<string> split(const string & str, char target) {
    vector<string> res;
    string s(str);
    int pos = 0;
    while (pos < s.size()) {
        for (; pos < s.size() && s[pos] == target; pos++);
        int start = pos;
        for (; pos < s.size() && s[pos] != target; pos++);
        if (pos > start) {
            res.push_back(s.substr(start, pos - start));
        }
    }
    return res;
}

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> se1 = split(sentence1, ' ');
        vector<string> se2 = split(sentence2, ' ');
        int n1 = se1.size();
        int n2 = se2.size();
        int i = 0, j = 0;
        for (; i < n1 && i < n2 && se1[i] == se2[i]; i++);
        for (; j < n1 - i && j < n2 - i && se1[n1 - j - 1] == se2[n2 - j - 1]; j++);
        return i + j == min(n1, n2);
    }
};




void test_solution() {
    Solution sol;
    string s1 = "My name is Haley", s2 = "My Haley";
    cout << "ans: true, got: " << sol.areSentencesSimilar(s1, s2) << endl;
    s1 = "of", s2 =  "A lot of words";
    cout << "ans: false, got: " << sol.areSentencesSimilar(s1, s2) << endl;
    s1 = "Eating right now", s2 = "Eating";
    cout << "ans: true, got: " << sol.areSentencesSimilar(s1, s2) << endl;
    s1 = "Eating right now", s2 = "now";
    cout << "ans: true, got: " << sol.areSentencesSimilar(s1, s2) << endl;
    s1 = "Eatings", s2 = "now";
    cout << "ans: false, got: " << sol.areSentencesSimilar(s1, s2) << endl;
    s1 = "Eatings 432", s2 = "Eatings 123";
    cout << "ans: false, got: " << sol.areSentencesSimilar(s1, s2) << endl;
    s1 = "Eatings 432 123", s2 = "Eatings 432 123";
    cout << "ans: true, got: " << sol.areSentencesSimilar(s1, s2) << endl;
}

void test_trim_space() {
    string a = "  Eating right now  ";
    string res = trim_space(a);
    cout << res << "\n";
}

void test_split_by_space() {
    string a = "  Eating right now  ";
    auto vi = split(a, ' ');
    for (auto v: vi) {
        cout << v << "\n";
    }
}

int main() {
    test_solution();
    return 0;
}