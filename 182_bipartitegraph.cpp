#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
int n;

bool isBipartite(int s){
    vector<int> col(n,-1);
    queue<int> q;
    q.push(s);
    col[s] = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cur = q.front();
            q.pop();
            if(G[cur][cur]) return false;
            int curcol = col[cur];
            for(int i=0;i<G[cur].size();i++){
                if(G[cur][i]){
                    if(col[i] == curcol) return false;
                    if(col[i]== -1){
                        col[i] = !curcol;
                        q.push(i);
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    G = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    n = G.size();

    isBipartite(0) ? cout << "Yes" : cout << "No";
    return 0;
}