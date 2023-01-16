
#include <string>
#include <vector>
#include <ctype.h> // isspace()
using namespace std;

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
