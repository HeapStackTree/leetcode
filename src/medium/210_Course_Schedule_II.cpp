#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> result;
    bool valid = true;
    void dfs(int u) {
        visited[u] = 1;
        for (int v: graph[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& prev: prerequisites) {
            graph[prev[1]].push_back(prev[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid) {
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution1 {
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> indegree;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses);
        indegree.resize(numCourses);
        for (const auto& prev: prerequisites) {
            graph[prev[1]].push_back(prev[0]);
            ++indegree[prev[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int visited = 0;
        vector<int> ans;

        while (!q.empty()) {
            ++visited;
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for (int v: graph[u]) {
                --indegree[v];
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (ans.size() != numCourses) {
            return {};
        }
        return ans;
    }
};