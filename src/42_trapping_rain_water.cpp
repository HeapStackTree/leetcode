#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int ans = 0;
//         stack<int> stk;
//         int n = height.size();
//         for (int i = 0; i < n; i++) {
//             while (!stk.empty() && height[i] > height[stk.top()]) {
//                 int top = stk.top();
//                 stk.pop();
//                 if (stk.empty()) break;
//                 int left = stk.top();
//                 int currWidth = i - left - 1;
//                 int currHeight = min(height[left], height[i]) - height[top];
//                 ans += currWidth * currHeight;
//             }
//             stk.push(i);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        
        return ans;
    }
};

int main() {
    vector<int> vi{6, 0, 6};
    Solution s = Solution();
    int ans = s.trap(vi);
    printf("%d\n", ans);
}