#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto x : nums) q.push(x);
        int i = 1;
        while(i++<k) q.pop();
        return q.top();
    }
};