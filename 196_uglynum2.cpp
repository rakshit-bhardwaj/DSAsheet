#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> q;
        long long int by2 = INT_MAX/2,by3 = INT_MAX/3,by5 = INT_MAX/5, count = 1;
        map<long long int,int> mapped;
        q.push(1);
        while(!q.empty()) {
            if(count++==n) return q.top();
            long long int cur = q.top();
            q.pop();
            if(cur >= by2 && !mapped[cur*2]) {
                q.push(2 * cur);
                mapped[cur*2] = 1;
            }
            if(cur >= by3 && !mapped[cur*3]) {
                q.push(3 * cur);
                mapped[cur*3] = 1;
            }
            if(cur >= by5 && !mapped[cur*5]){
                q.push(5 * cur);
                mapped[cur*5] = 1;
            } 
        }
        return q.top();

    }
};

