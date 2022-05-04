#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[x++]=nums[i];
            }
        }
       return x; 
    }
};