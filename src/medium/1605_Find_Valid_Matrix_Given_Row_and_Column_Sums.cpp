#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> vec(rows, vector<int>(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rowSum[i] == 0) break;
                int value = rowSum[i] < colSum[j] ? rowSum[i] : colSum[j];
                vec[i][j] = value;
                rowSum[i] -= value;
                colSum[j] -= value;
            }
        }
        return vec;
    }
};