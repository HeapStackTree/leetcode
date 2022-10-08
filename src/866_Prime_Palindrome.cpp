#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int primePalindrome(int N) {
        while (true) {
            // if (N == reverse(N) && isPrime(N))
            if (checkPalindrome(N) && isPrime(N))
                return N;
            N++;
            if (10000000 < N && N < 100000000)
                N = 100000000;
        }
    }

    bool isPrime(int N) {
        if (N < 2) return false;
        int R = (int) sqrt(N);
        for (int d = 2; d <= R; ++d)
            if (N % d == 0) return false;
        return true;
    }
    bool checkPalindrome(int N) {
        // string s = to_string(N);
        // int l = 0, r = s.size() - 1;
        // while (l < r) {
        //     if (s[l] != s[r]) return false;
        //     l++;
        //     r--;
        // }
        if (N == reverse(N)) return true;
        return false;
    }
    int reverse(int N) {
        int ans = 0;
        while (N > 0) {
            ans = 10 * ans + (N % 10);
            N /= 10;
        }
        return ans;
    }
};