#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right && s[left] == s[right]) {
            left++;
            right--;
        }
        return left >= right;
    }

    bool checkConcatenation(const string &a, const string &b) {
        int left = 0, right = a.size() - 1;
        while (left < right && a[left] == b[right]) {
            left++;
            right--;
        }
        if (left >= right) {
            return true;
        }
        return isPalindrome(a, left, right) || isPalindrome(b, left, right);
    } 
    bool checkPalindromeFormation(string a, string b) {
        return checkConcatenation(a, b) || checkConcatenation(b, a);
    }
};