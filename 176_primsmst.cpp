#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mst;

void prims(vector<vector<int>> edges){
    int n = edges.size();
    vector<int> mstv;
    map<pair<int,int>,int> m;
    mst.resize(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        mst[i][i]  = 0;
    }
    mstv.push_back(0);
    while(mstv.size()!=n){
        int mine = -1;
        pair<int,int> minedge;
        for(auto x: mstv){
            for(int j=0;j<n;j++){
                if(x == j || edges[x][j] == -1 || m[{x,j}]) continue;
                if(mine==-1 || edges[x][j]<mine){
                    //cout<<"current min edge ["<<x<<" -> "<<j<<"] "<<edges[x][j]<<endl;
                    mine = edges[x][j];
                    minedge.first = x;
                    minedge.second = j;
                }
            }
        }
        //cout<<"selected edge ["<<minedge.first<<" -> "<<minedge.second<<"] "<<mine<<endl;
        m[minedge] = 1;
        m[{minedge.second,minedge.first}] = 1;
        mst[minedge.first][minedge.second] = mine;
        mstv.push_back(minedge.second);
    }
}

int main (){
    vector<vector<int>> edges = { { 0, 2, -1, 6, -1 },
                                  { 2, 0, 3, 8, 5 },
                                  { -1, 3, 0, -1, 7 },
                                  { 6, 8, -1, 0, 9 },
                                  { -1, 5, 7, 9, 0 } };
    prims(edges);
    for(int i =0;i<mst.size();i++){
        cout<<i<<" -> ";
        for(int j=0;j<mst[i].size();j++){
            if(mst[i][j]>0){
                cout<<"["<<j<<","<<mst[i][j]<<"] ";
            }
        }
        cout<<endl;
    }
    return 0;
}