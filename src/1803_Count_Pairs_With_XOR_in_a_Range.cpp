#include <vector>
#include <iostream>
using namespace std;

// Solution from https://leetcode.com/problems/count-pairs-with-xor-in-a-range/solutions/1120320/C++-Clear-Explanation-of-Trie-Tree-Solution/comments/897071/

#define LEVEL 16 // 1 <= nums[i] <= 20000

struct TrieNode {
    TrieNode *child[2];
    int cnt;
    TrieNode() {
        child[0] = child[1] = nullptr;
        cnt = 0;
    }
};

// Function to insert a number into Trie
void insertTrie(TrieNode *root, int n) {
    for (int i = LEVEL; i >= 0; i--) {
        bool x = n & (1 << i);
        if (!root->child[x]) {
            root->child[x] = new TrieNode();
        }
        root = root->child[x];
        root->cnt += 1;
    }
}

class Solution {
private:
    // Count elements in Trie whose XOR with N less than K
    int countSmallerPairs(TrieNode *root, int N, int K) {
    //  Stores count of elements whose XOR with N less than K
        int cntPairs = 0;
        for (int i = LEVEL; i >= 0 && root; i--) {
            bool x = N & (1 << i); // Store ith bit of N
            bool y = K & (1 << i); // Store ith bit of K

            // If the ith bit of K is 0
            if (y == 0) {
                // find the number which bit is same as N
                // so that they can be xored to ZERO
                root = root->child[x];
                continue;
            }

            // If the ith bit of K is 1
            // If an element already present in Trie having ith bit (x)
            if (root->child[x]) {
                // fint th number which bit is same as N
                // so that they can be xored to ZERO. so it would be smaller than K
                cntPairs += root->child[x]->cnt;
            }
            // go to another way for next bit count
            root = root->child[1 - x];
        }
        return cntPairs;
    }

public:
    int countPairs(vector<int>& nums, int low, int high) {
        TrieNode *root = new TrieNode();

        int cnt = 0;
        for (auto& num: nums) {
            cnt += countSmallerPairs(root, num, high+1) - countSmallerPairs(root, num, low);
            insertTrie(root, num);
        }
        return cnt;
    }
};


int main() {
    vector<int> nums{9, 8, 4, 2, 1};
    int low = 5, high = 14;
    Solution s;
    cout << s.countPairs(nums, low, high) << endl;
    return 0;
}

