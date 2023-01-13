#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        int srcs[26] = {0};
        int targets[26] = {0};
        for (char c : target)
        {
            targets[c - 'a']++;
        }
        for (char c : s)
        {
            if (targets[c - 'a'])
            {
                srcs[c - 'a']++;
            }
        }
        int res = 100;
        for (int i = 0; i < 26; i++)
        {
            if (targets[i] != 0)
            {
                res = min(srcs[i] / targets[i], res);
            }
        }
        return res;
    }
};

int main()
{
    string src = "ilovecodingonleetcode";
    string target = "code";
    Solution sol;
    cout << sol.rearrangeCharacters(src, target) << endl;
    return 0;
}