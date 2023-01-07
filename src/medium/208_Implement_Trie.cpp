#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode(): children(26), isEnd(false) {}
};

class Trie {
private:
    TrieNode* trieNode;

    TrieNode *searchPrefix(string prefix) {
        TrieNode *node = trieNode;
        for (char ch: prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie(): trieNode{new TrieNode()} {}
    
    void insert(string word) {
        TrieNode* node = trieNode;
        for (char ch: word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */