#include<bits/stdc++.h>
using namespace std;

int peak(vector<int> nums){
    if(nums.size()==1) return 0;
    int s = 0;
    int e = nums.size()-1;
    while(s<=e){
        int m = (s+e)/2;
        if(m>0 && m<nums.size()-1 && nums[m]>nums[m-1] && nums[m] > nums[m+1]) return m;
        else if(m == 0 && nums[m]>nums[m+1]) return m;
        else if(m==nums.size()-1 && nums[m]>nums[m-1]) return m; 
        else {
            if(nums[m] <nums[m+1]) s = m + 1;
            else e = m ;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1,2};
    cout<<peak(nums);
}