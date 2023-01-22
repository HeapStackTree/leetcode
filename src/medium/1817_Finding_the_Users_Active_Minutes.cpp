#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> timeMap;
        vector<int> result(k);
        for (auto &log: logs) {
            timeMap[log[0]].emplace(log[1]);
        }
        for (auto &i: timeMap) {
            result[i.second.size() - 1]++;
        }
        return result;
    }
};

void testSolution() {
    Solution sol;
    vector<vector<int>> logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    int k = 5;
    for (auto i : sol.findingUsersActiveMinutes(logs, k)) {
        cout << i << ", ";
    }
    cout << endl;
    logs = {{1,1},{2,2},{2,3}};
    k = 4;
    for (auto i : sol.findingUsersActiveMinutes(logs, k)) {
        cout << i << ", ";
    }
    cout << endl;


}

int main() {
    testSolution();
    return 0;
}