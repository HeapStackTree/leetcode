#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        vector<vector<bool>> connect(n, vector<bool>(n));
        int m = roads.size();
        for (int i = 0; i < m; i++) {
            int x = roads[i][0], y = roads[i][1];
            degree[x]++;
            degree[y]++;
            connect[x][y] = connect[y][x] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, degree[i] + degree[j] - connect[i][j]);
            }
        }
        return ans;
    }
};

void test_Solution() {
    Solution sol;
    vector<vector<int>> roads{{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    int n = 5;
    int ans = sol.maximalNetworkRank(8, roads);
    cout << ans << "\n";
    
}

int main() {
    test_Solution();
    return 0;
}