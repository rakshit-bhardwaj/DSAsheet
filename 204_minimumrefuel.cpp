#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int count =0;
        int cur = startFuel;
        int i =0;
        int n = stations.size();

        while(cur<target){
            while(i<n && cur>= stations[i][0]){
                q.push(stations[i][1]);
                i++;
            }

            if(q.empty()) return -1;

            cur+=q.top();
            q.pop();
            count++;
        }
        return count;
    }
};