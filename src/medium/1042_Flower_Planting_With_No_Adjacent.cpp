#include <vector>
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n + 1);
        for (auto& vec: paths) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        vector<int> ans(n);
        for (int i = 1; i < n + 1; i++) {
            vector<int> color(5);
            for (int& j: graph[i]) {
                color[ans[j - 1]] = 1;
            }
            for (int k = 1; k < 5; k++) {
                if (color[k] == 0) {
                    ans[i - 1] = k;
                    break;
                }
            }
        }
        return ans;
    }
};