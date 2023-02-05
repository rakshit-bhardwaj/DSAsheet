#include <bits/stdc++.h>
using namespace std;

class disjointset
{
public:
    vector<int> rank, parent, size;
    disjointset(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUparent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findUparent(parent[x]);
    }
    void unionbyRank(int u, int v)
    {
        int pu = findUparent(u);
        int pv = findUparent(v);
        if (pu == pv)
            return;
        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else if (rank[pv] > rank[pu])
            parent[pu] = pv;
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionbySize(int u, int v)
    {
        int pu = findUparent(u);
        int pv = findUparent(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};


class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int m, n;

    bool checkp(int x,int y){
        if(x <0 || y<0 || x >= n || y >= m) return false;
        return true;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size(); m = grid[0].size();
        disjointset o(m*n);

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    for(int k =0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(checkp(ni,nj) && grid[ni][nj]){
                            int cnode = i * m + j;
                            int anode = ni * m + nj;
                            o.unionbySize(cnode,anode);
                        }
                    }
                }
            }
        }

        set<int> cp;
        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]){
                    for(int k =0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(checkp(ni,nj) && grid[ni][nj]){
                            cp.insert(o.findUparent(ni * m + nj));
                        }
                    }
                    int cursum = 1;
                    for(auto x : cp) cursum += o.size[x];
                    ans = max(ans,cursum);
                    cp.clear();
                }
            }
        }
        if(ans == INT_MIN) return n*m;
        return ans;
    }
};

