#include <vector>
#include <queue>
using namespace std;

class Solution {
    vector<vector<int>> graph;
    vector<int> visited;
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
            if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        return valid;
    }
};

class Solution1 {
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> indegree;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: graph[u]) {
                --indegree[v];
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};