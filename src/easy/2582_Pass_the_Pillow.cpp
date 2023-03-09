#include <iostream>
using namespace std;
class Solution {
public:
    int passThePillow(int n, int time) {
        int m = time % (2 * n - 2);

        if (m > n-1) return n - (m - n + 1);
            else return 1 + m;
    }
};

void test_Solution() {
    Solution sol;
    cout << sol.passThePillow(4, 5);
}

int main() {

    return 0;
}