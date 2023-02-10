#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<int/*remove this int*/>> q;
        int i =0,j = 0,n = matrix.size(),ans;
        for(int i =0;i < min(k,n);i++){
            q.push({matrix[i][0],i,0});
        }

        for(int i =1; i<=k;i++){
            auto cur = q.top();
            q.pop();
            ans = cur[0];
            if(cur[2] < n - 1) q.push({matrix[cur[1]][cur[2] + 1],cur[1],cur[2]+1});
        }
       
        return ans;
    }
};


