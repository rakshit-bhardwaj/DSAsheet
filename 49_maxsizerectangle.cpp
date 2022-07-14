#include<bits/stdc++.h>
using namespace std;

vector<int> prevs(vector<int> hist){
    stack <int> s;
    vector <int> ps(hist.size());
    for(int i=0;i<hist.size();i++){
        while(!s.empty() && hist[s.top()]>=hist[i]){
            s.pop();
        }
        
        if(s.empty()) ps[i]=-1;
        else {
            ps[i] = s.top();
        }
        s.push(i);
    }
    return ps;  
}

vector<int> nexs(vector<int> hist){
    stack <int> s;
    vector <int> ns(hist.size(),0);
    for(int i=hist.size()-1;i>=0;i--){
        while(!s.empty() && hist[s.top()]>=hist[i]){
            s.pop();
        }
        if(s.empty()) ns[i]=hist.size();
        else {
            ns[i] = s.top();
        }
        s.push(i);
    }
    return ns;  
}


int histogram(vector<int> hist){
    int area,maxarea = INT_MIN;
    vector<int> ps = prevs(hist);
    vector<int> ns = nexs(hist);
    cout<<"current row ->"<<endl;
    for(int i=0;i<hist.size();i++){
        cout<<hist[i]<<" ";
        area = (ns[i] - ps[i] - 1) * hist[i];
        maxarea = max(area,maxarea);
    }
    cout<<"max area = "<<maxarea<<endl;
    cout<<"xxxxxxxxxxxxxx"<<endl;
    return maxarea;
}

int maxsizbinaryrect(vector<vector<int>> rect){
    vector<int> currow;
    int maxarea = INT_MIN;
    currow = rect[0];
    for(int i=0;i<rect.size();i++){
        if(i!=0){
            for(int j=0;j<rect[0].size();j++){
                if(rect[i-1][j]==0) currow[j]=0;
                else {
                    currow[j]+=1;
                }
            }
        }
        
        maxarea = max(histogram(currow),maxarea);
    }
    return maxarea;
}

int main () {
    vector<vector<int>> rect = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    cout<<maxsizbinaryrect(rect);
    return 0;
}