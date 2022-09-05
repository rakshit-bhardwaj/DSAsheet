#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> m;
        vector<int> nge(nums2.size());
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]] = -1;
        }
        for(int i = nums2.size()-1;i>=0;i--){
            while(!s.empty()){
                if(s.top()>nums2[i]){
                    m[nums2[i]] = s.top();
                    break;
                }
                s.pop();
            }
            if(s.empty()) m[nums2[i]]  = -1;
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
            
        return ans;
    }
};