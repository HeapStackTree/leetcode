class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int commonFactors(int a, int b) {
        int gfactor = gcd(a, b);
        int ans = 0;
        for (int i = 1; i * i <= gfactor; ++i) {
            if (gfactor % i == 0) {
                ++ans;
                if (i * i != gfactor) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};