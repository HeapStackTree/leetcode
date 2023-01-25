#include <memory.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public: 
//  并查集用于合并行或列相同的元素
    const static int LIM = 512; 
    int unions[LIM*2]; 
    int find(int i){
        if(unions[i] == i)return i; 
        unions[i] = find(unions[i]); 
        return unions[i]; 
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size(); 
        vector<vector<int>> res(R, vector<int>(C, 0)); 
        int countR[R], countC[C]; 
        memset(countR, 0, sizeof(countR)); 
        memset(countC, 0, sizeof(countC)); 

        // 按元素大小分别存储元素
        unordered_map<int, vector<int>> ls, pool; 
        for(int r = 0; r<R; r++){
            for(int c = 0; c<C; c++){
                ls[matrix[r][c]].push_back(r*LIM+c); 
            }
        }

        // 初始化并查集
        for(int i = 0; i<LIM*2; i++) unions[i] = i; 

        // 按从小到大的顺序遍历
        int values[ls.size()], i = 0; 
        for(auto p: ls) values[i++] = p.first;
        sort(values, values+ls.size()); 
        for(int val: values){

            // 用并查集合并行和列相同的元素并分组
            for(int pt: ls[val]){
                unions[find(pt/LIM)] = find((pt%LIM)+LIM); 
            }
            pool.clear(); 
            for(int pt: ls[val]){
                pool[find(pt/LIM)].push_back(pt); 
            }

            // 行/列相同的元素，共享相同的rank
            for(pair<int, vector<int>> group: pool){
                int rank = 0; 
                for(int pt: group.second){
                    rank = max(rank, max(countR[pt/LIM], countC[pt%LIM])); 
                }
                rank += 1; 
                for(int pt: group.second){
                    int r = pt/LIM, c = pt%LIM; 
                    countR[r] = countC[c] = res[r][c] = rank; 
                    // 重置并查集
                    unions[r] = r; 
                    unions[c+LIM] = c+LIM; 
                }
            }
        }
        return res; 
    }
}; 