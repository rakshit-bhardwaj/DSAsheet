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
        size.resize(n + 1,1);
        for(int i =0;i<=n;i++){
            parent[i] = i;
        }
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        unordered_map<int, int> stonenode;
        int maxr = 0, maxc = 0;
        for (auto x : stones)
        {
            maxr = max(maxr, x[0]);
            maxc = max(maxc, x[1]);
        }

        disjointset o(maxr + maxc + 1);

        for (auto x : stones)
        {
            int rownode = x[0];
            int colnode = x[1] + maxr + 1;
            o.unionbySize(rownode, colnode);
            stonenode[rownode] = 1;
            stonenode[colnode] = 1;
        }

        int count = 0;

        for (auto x : stonenode)
        {
            if (x.first == o.findUparent(x.first))
                count++;
        }

        return n - count;
    }
};