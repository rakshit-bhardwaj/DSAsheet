#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(),d,i=0;
        priority_queue <int> q;
        for(i =0;i<n-1;i++){
            if(heights[i]>=heights[i+1]) continue;
            d = heights[i+1] - heights[i];
            if(bricks >= d){
                bricks -= d;
                q.push(d);
            } else if(ladders > 0) {
                if(q.size()){
                    int maxd = q.top();
                    if(d < maxd){
                         q.pop();
                        bricks+=maxd - d;
                        q.push(d);
                    }
                }
                ladders--;
            } else break;
        }

        return i;

    }
};