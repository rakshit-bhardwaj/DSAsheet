#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
       int moves = 0,min = INT_MAX;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<min) min = nums[i];
       }
       for(int i=0;i<nums.size();i++){
        moves += nums[i] - min;
       }
       return moves;
    }
};