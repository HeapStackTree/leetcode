#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> answer;
        for (auto &circle: queries) {
            int ans = 0;
            for (auto &p: points) {
                int a = p[0] - circle[0];
                int b = p[1] - circle[1];
                int r = circle[2];
                if (a * a + b * b <= r * r) {
                    ans++;
                }
            }
            answer.push_back(ans);
        }
        return answer;
    }
};

void coutVector(vector<int> ve) {
    cout << "[";
    for (int &i: ve) {
        cout << i << ", ";
    }
    cout << "]" << endl;
}

void testSolution() {
    Solution sol;
    vector<vector<int>> points = {{1,3},{3,3},{5,3},{2,2}};
    vector<vector<int>> queries =  {{2,3,1},{4,3,1},{1,1,2}};
    coutVector(sol.countPoints(points, queries));
    points =  {{1,1},{2,2},{3,3},{4,4},{5,5}};
    queries = {{1,2,2},{2,2,2},{4,3,2},{4,3,3}};
    coutVector(sol.countPoints(points, queries));
}

int main() {
    testSolution();
    return 0;
}