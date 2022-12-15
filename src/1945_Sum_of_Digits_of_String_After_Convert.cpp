#include <stdio.h>
#include <string>

using namespace std;
class Solution
{
public:
    int getLucky(string s, int k)
    {
        string number_str = "";
        for (int i = 0; i < s.size(); i++)
        {
            number_str += to_string(s[i] - 'a' + 1);
        }
        int res = 0;
        for (int i = 0; i < k; i++)
        {
            res = 0;

            for (int j = 0; j < number_str.size(); j++)
            {

                res += number_str[j] - '0';
            }

            number_str = to_string(res);
        }
        return res;
    }
};

int main()
{
    string s = "leetcode";
    int k = 2;
    Solution sol;
    printf("%d\n", sol.getLucky(s, k));
    return 0;
}