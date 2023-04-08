#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> skill_index;
        for (int i = 0; i < n; i++) {
            skill_index[req_skills[i]] = i;
        }
        vector<int> dp(1 << n, m);
        vector<int> prev_skill(1 << n, 0);
        vector<int> prev_people(1 << n, 0);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            int cur_skill = 0;
            for (string& skill: people[i]) {
                cur_skill |= 1 << skill_index[skill];
            }
            for (int prev = 0; prev < (1 << n); prev++) {
                int comb = prev | cur_skill;
                if (dp[prev] + 1 < dp[comb]) {
                    dp[comb] = dp[prev] + 1;
                    prev_skill[comb] = prev;
                    prev_people[comb] = i;
                }
            }
        }
        vector<int> ans;
        int i = (1 << n) - 1;
        while (i > 0) {
            ans.push_back(prev_people[i]);
            i = prev_skill[i];
        }
        return ans;
    }
};

void test_Solution() {
    Solution sol;
    vector<string> req_skills = {"java", "nodejs", "reactjs"};
    vector<vector<string>> people = {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
    auto ans = sol.smallestSufficientTeam(req_skills, people);
    for (int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    test_Solution();
    return 0;
}