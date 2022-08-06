#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0,e = nums.size()-1,m;
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        }
        while(s<=e){
            int m = (s+e)/2;
            if(nums[m]==target) return m;
            if(nums[s] <= nums[m]){
                if(target >= nums[s] && target <= nums[m]){
                    e = m-1;
                } else {
                    s = m+1;
                }
            } else {
                if(target >= nums[m] && target <= nums[e]){
                    s = m+1;
                } else {
                    e = m-1;
                }
            }
        }
        return -1;
    }
};

// 2 4 5 6 7 0 1 
