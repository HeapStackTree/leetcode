// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    void dfs(TreeNode* node, int valMin, int valMax, int& ans) {
        
        if (node->val > valMax) {
            valMax = node->val;
        } else if (node->val < valMin) {
            valMin = node->val;
        }
        if (valMax - valMin > ans) {
            ans = valMax - valMin;
        }
        if (node->left != nullptr) {
            dfs(node->left, valMin, valMax, ans);
        }
        if (node->right != nullptr) {
            dfs(node->right, valMin, valMax, ans);
        }
    };
    int maxAncestorDiff(TreeNode* root) {
        int valMin, valMax;
        valMin = valMax = root->val;
        int ans = 0;
        dfs(root, valMin, valMax, ans);
        return ans;
    }
};