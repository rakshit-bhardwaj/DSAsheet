#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        map<int, int> vis;
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int cur = q.front();
            ans.push_back(cur);
            q.pop();
            for (auto x : adj[cur])
            {
                if (vis[x] == 0)
                {
                    vis[x] = 1;
                    q.push(cur);
                }
            }
        }

        return ans;
    }
};