#include <stdio.h>
#include <iostream>


class Solution {
public:

    long cal(long n, long midV) {
        midV = midV - 1;
        if (n == 0) return 0;
        if (n > midV) return (midV + 1) * midV / 2 + n - midV;
        return (midV + midV - n + 1) * n / 2;
    }
    
    bool valid(int n, int index, long maxSum, int midV) {
        long leftSum = cal(index, midV);
        long rightSum = cal(n - index - 1, midV);
        return leftSum + rightSum + midV <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (valid(n, index, maxSum, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    int n = 4, index = 2, maxSum = 6;
    Solution s;
    std::cout << s.maxValue(4, 2, 6) << std::endl;
}