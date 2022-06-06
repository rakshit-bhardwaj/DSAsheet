#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int64_t maxa=INT_MIN,area;
        int64_t s=0,e=height.size()-1;
        while(e!=s){
            area=(e-s)*(min(height[e],height[s]));
            maxa = max(maxa,area);
            height[s] >= height[e] ? e-- : s++;
        }
        return maxa;
    }
};