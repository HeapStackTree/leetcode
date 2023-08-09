class Solution {
public:
    int subtractProductAndSum(int n) {
        int digit = n % 10;
        int mulAccu = digit;
        int addAccu = digit;
        n /= 10;
        while (n != 0) {
            digit = n % 10;
            mulAccu *= digit;
            addAccu += digit;
            n /= 10;
        }
        return mulAccu - addAccu;
    }
};