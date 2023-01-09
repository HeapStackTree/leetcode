#include <vector>
#include <iostream>
#include <string>
using namespace std;

// class Solution {
// private:
// bool isSame(vector<int>& a, vector<int>& b) {
//     if (a.size() != b.size()) return false;
//     for (int i = 0; i < a.size(); i++) {
//         if (a[i] != b[i]) return false;
//     }
//     return true;
// }

// void reOrder(vector<int> &arr, vector<int> &perm) {
//     if (arr.size() != perm.size()) return;
//     int n = arr.size();
//     for (int i = 0; i < n; i++) {
//         if (i % 2 == 0) {
//             arr[i] = perm[i / 2];
//         } else {
//             arr[i] = perm[n / 2 + (i - 1) / 2];
//         }
//     }
// }

// public:
//     int reinitializePermutation(int n) {
//         vector<int> perm(n);
//         vector<int> arr(n);
//         vector<int> newPerm(n);
//         for (int i = 0; i < n; i++) {
//             perm[i] = i;
//         }
//         reOrder(arr, perm);
//         int cnt = 1;
//         while (!isSame(arr, perm)) {
//             newPerm = arr;
//             reOrder(arr, newPerm);
//             cnt += 1;
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) {
            return 1;
        }
        int step = 1, pow2 = 2;
        while (pow2 != 1) {
            step++;
            pow2 = pow2 * 2 % (n - 1);
        }
        return step;
    }
};

int main() {
    Solution s;
    int n = 2;
    cout << s.reinitializePermutation(n) << endl;
    n = 4;
    cout << s.reinitializePermutation(n) << endl;
    n = 6;
    cout << s.reinitializePermutation(n) << endl;
    return 0;
}