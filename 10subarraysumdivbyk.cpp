#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int i,j,count=0,rem,cursum=0;
        map<int,int> freq;
        freq[0]++;
        for(i=0;i<nums.size();i++){
            cursum+=nums[i];
            rem=cursum%k;
            if(rem<0) rem +=k;
            freq[rem]++;
            if(freq[rem]>1){
                count +=freq[rem] - 1;
            }        
        }
        return count;
    }
};