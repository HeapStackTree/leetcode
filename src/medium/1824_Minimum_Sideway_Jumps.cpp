#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0X3F3F3F3F
class Solution {
public:
    int minSideJumps(vector<int> &obstacles) {
        int n = obstacles.size();
        vector<int> dp{1, 0, 1};
        for (int i = 1; i < n; i++) {
            int minJumps = INF;
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] - 1 == j) {
                    dp[j] = INF;
                } else {
                    minJumps = min(minJumps, dp[j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] - 1 == j) {
                    continue;
                }
                dp[j] = min(dp[j], minJumps + 1);
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};

void testSolution() {
    Solution sol;
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << sol.minSideJumps(obstacles) << endl;
    obstacles = {0, 1, 1, 3, 3, 0};
    cout << sol.minSideJumps(obstacles) << endl;
    obstacles = {0, 2, 1, 0, 3, 0};
    cout << sol.minSideJumps(obstacles) << endl;
}

int main() {
    testSolution();
    return 0;
}