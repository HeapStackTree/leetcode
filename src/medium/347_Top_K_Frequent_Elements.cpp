#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (int& i: nums) {
            occurrences[i]++;
        }
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);
        for (auto& it: occurrences) {
            maxHeap.push(it);
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            auto p = maxHeap.top();
            maxHeap.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};