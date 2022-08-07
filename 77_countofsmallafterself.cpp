#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<pair<int,int>> &v,vector<int> &count,int l,int m, int r){
        int x = 0,i = l,j = m+1;
        vector<pair<int,int>> temp(r-l+1);
        while(i<=m && j<=r){
            if(v[i].first <= v[j].first){
                temp[x++] = v[j++];
            } else {
                count[v[i].second] += r-j+1;
                temp[x++] = v[i++];
            }
        }
        while(i<=m){
            temp[x++] = v[i++];
        }
        while(j<=r){
            temp[x++] = v[j++];
        }
        for(int i=l;i<=r;i++){
            v[i] = temp[i-l];
        }
    }
    void merge_sort(vector<pair<int,int>> &v,int l,int r,vector<int> &count){
        if(l<r){
            int m = (r + l)/2;
            merge_sort(v,l,m,count);
            merge_sort(v,m+1,r,count);
            merge(v,count,l,m,r);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> v(nums.size());
        vector<int> count(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            v[i] = {nums[i],i};
        }
        merge_sort(v,0,nums.size()-1,count);
        return count;
    }
};

int main (){
    Solution obj;
    vector <int> nums = {5,2,6,1};
    vector<int> ans = obj.countSmaller(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}