#include <vector>
#include <utility>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, int>> stk;
        ListNode* cur = head;
        int idx = 0;
        while (cur != nullptr) {
            ans.push_back(0);
            while (!stk.empty() && cur->val > stk.top().first) {
                ans[stk.top().second] = cur->val;
                stk.pop();
            }
            stk.push({cur->val, idx});
            cur = cur->next;
            idx++;
        }
        return ans;
    }
};