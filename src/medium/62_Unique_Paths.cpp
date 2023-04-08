class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int i = m, j = 1; i < m + n - 1, j < n; i++, j++) {
            ans = ans * i / j;
        }
        return ans;
    }
};