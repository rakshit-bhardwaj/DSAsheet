#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<float,set<pair<int,int>>> slope;
        int maxcount=0;
        float m;
        if(points.size()==1) return 1;
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                if(points[j][0] - points[i][0] == 0) m = INT_MAX;
                else m = float (points[j][1] - points[i][1])/float (points[j][0] - points[i][0]);
                slope[m].insert({points[j][0],points[j][1]});
                slope[m].insert({points[i][0],points[i][1]});
                cout<<"point1 => {"<<points[i][0]<<", "<<points[i][1]<<"}\n";
                cout<<"point2 => {"<<points[j][0]<<", "<<points[j][1]<<"}\n";
                cout<<"slope = "<<m<<endl;
                cout<<"Elements on this slope = "<<slope[m].size()<<endl;
                cout<<"xxxxxxxxxxxxxxxxxx\n";
                if(slope[m].size()>maxcount) maxcount = slope[m].size();
            }
            slope.clear();
        }
        return maxcount;
    }
};


