#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q;
        double sum = 0;
        for (int i: nums) {
            q.push(i);
            sum += i;
        }
        double sumHalve = sum / 2;
        int ops = 0;
        while (sum > sumHalve) {
            double t = q.top();
            q.pop();
            t /= 2;
            sum -= t;
            q.push(t);
            ops++;
        }
        return ops;
    }
};