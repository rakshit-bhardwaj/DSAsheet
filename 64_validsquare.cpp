#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<float> s;
        s.push_back(sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1])));
        s.push_back(sqrt((p2[0] - p3[0])*(p2[0] - p3[0]) + (p2[1] - p3[1])*(p2[1] - p3[1])));
        s.push_back(sqrt((p3[0] - p4[0])*(p3[0] - p4[0]) + (p3[1] - p4[1])*(p3[1] - p4[1])));
        s.push_back(sqrt((p4[0] - p1[0])*(p4[0] - p1[0]) + (p4[1] - p1[1])*(p4[1] - p1[1])));
        s.push_back(sqrt((p1[0] - p3[0])*(p1[0] - p3[0]) + (p1[1] - p3[1])*(p1[1] - p3[1])));
        s.push_back(sqrt((p2[0] - p4[0])*(p2[0] - p4[0]) + (p2[1] - p4[1])*(p2[1] - p4[1])));
        sort(s.begin(),s.end());
        map <pair<int,int>,int> freq;
        freq[{p1[0],p1[1]}]++;
        freq[{p2[0],p2[1]}]++;
        if(freq[{p2[0],p2[1]}]>1) return false;
        freq[{p3[0],p3[1]}]++;
        if(freq[{p3[0],p3[1]}]>1) return false;
        freq[{p4[0],p4[1]}]++;
        if(freq[{p4[0],p4[1]}]>1) return false;

        for(int i=0;i<4;i++){
            cout<<"side "<<i+1<<" = "<<s[i]<<endl;
        }
        for(int i=4;i<6;i++){
            cout<<"diagonal "<<i-3<<" = "<<s[i]<<endl;
        }
        cout<<"root 2 x side  = "<<s[0] * sqrt(2)<<endl;
        float checkside = s[0];
        for(int i=1;i<4;i++){
            if(abs(s[i] - checkside) > 0.001){
                cout<<"sides dont match\n";
                cout<<"side 1 = "<<checkside<<" side "<<i+1<<" = "<<s[i]<<endl;
                cout<<"xxxxxxxxxxxxxx"<<endl;
                return false;
            }
        }
        
        if(s[4]!=s[5]){
            cout<<"diagnols dont match\n";
            cout<<"xxxxxxxxxxxxxx"<<endl;
            return false;
        }
        if(abs(sqrt(2) * s[0] - s[4]) > 0.001){
            cout<<"sides * root 2 is not equal to diagnol\n";
            cout<<"xxxxxxxxxxxxxx"<<endl;
            return false;
        }
        cout<<"square\n";
        cout<<"xxxxxxxxxxxxxx"<<endl;
        return true;
    }
};