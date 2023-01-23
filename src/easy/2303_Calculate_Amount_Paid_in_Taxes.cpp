#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int lastUp = 0;
        int taxRate = 0;
        int tax = 0;
        for (int i = 0; i < brackets.size(); i++) {
            int interval = brackets[i][0] - lastUp;
            taxRate = brackets[i][1];
            if (income < interval) {
                tax += income * taxRate;
                break;
            } else {
                tax += interval * taxRate;
            }
            income -= interval;
            lastUp = brackets[i][0];
        }
        return (double(tax) / 100);
    }
};

void testSolution() {
    Solution sol;
    vector<vector<int>> brackets = {{3,50},{7,10},{12,25}};
    int income = 10;
    cout << sol.calculateTax(brackets, income) << endl;
    brackets = {{1,0},{4,25},{5,50}};
    income = 2;
    cout << sol.calculateTax(brackets, income) << endl;
    brackets =  {{2,50}};
    income = 0;
    cout << sol.calculateTax(brackets, income) << endl;
}

int main() {
    testSolution();
    return 0;
}