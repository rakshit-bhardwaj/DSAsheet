#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mapped;
vector<pair<int,int>> dir = {{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{0,1}};

bool check(int i,int j,pair<int,int> d,int r,int c){
    if(i+d.first >= r || i+d.first<0) return false;
    if(j+d.second >= c || j+d.second<0) return false;
    return true;
}

bool dfs(vector<vector<int>> m,int i,int j){
    bool c1 = false;
    cout<<"current position -> { "<<i<<" , "<<j<<" }"<<endl;
    if(m[i][j]==1 && count(mapped.begin(),mapped.end(),make_pair(i,j)) == 0 ){
        cout<<"mapped -> { "<<i<<" , "<<j<<" }"<<endl;
        mapped.push_back({i,j});
        c1 = true;
    }else return false;

    for(int k=0;k<dir.size();k++){
        if(check(i,j,dir[k],m.size(),m[0].size())) dfs(m,i + dir[k].first,j+dir[k].second);
    } 
    return c1;
}

int islands(vector<vector<int>> m){
    int c = 0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            if(count(mapped.begin(),mapped.end(),make_pair(i,j)) == 0){
                if(dfs(m,i,j)) c++;
                cout<<"current count = "<<c<<endl;
                cout<<"\nxxxxxxxxxxxxxxxxxxxxxx\n";
            }
        }
    }
    return c;
}

int main() {
    vector<vector<int>> m = 
    {{1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1}};
    cout<<islands(m);
    return 0;
}