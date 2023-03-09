#include <iostream>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0;
        int cnt = 0;
        while(r < k) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            r++;
        }
        int res = k;
        while (r < blocks.size()) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            cnt -= blocks[l] == 'W' ? 1 : 0;
            res = cnt < res ? cnt : res;
            l++;
            r++;
        }
        return res;
    }
};