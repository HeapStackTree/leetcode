#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void DFS(TreeNode *node, unordered_map<int, long long> &mp, int height) 
    {
        mp[height] += node->val;
        if (node->left != nullptr) {
            DFS(node->left, mp, height+1);
        }
        if (node->right != nullptr) {
            DFS(node->right, mp, height+1);
        }
    }
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        unordered_map<int, long long> mp;
        DFS(root, mp, 0);
        vector<long long> vec;
        int maxLevel = 0;
        for (auto &it: mp) {
            if (it.first > maxLevel) {
                maxLevel = it.first;
            }
            vec.push_back(it.second);
        }
        if (maxLevel < k - 1) {
            return -1;
        }
        sort(vec.begin(), vec.end(), [](long long a, long long b) {return a > b;});
        
        return vec[k - 1];
    }
};