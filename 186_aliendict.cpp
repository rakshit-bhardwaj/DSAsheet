#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    map<int,vector<int>> m;
    unordered_map<int,int> vis;
    stack<int> s;

    void mapper(int n1,int n2){
        m[n1].push_back(n2);
    }

    void dfs(int x){
        vis[x] = 1;
        for(auto i : m[x]){
            if(!vis[i]){
                dfs(i);
            }
        }
        s.push(x);
    }


    string findOrder(string dict[], int N, int K) {
       
       string ans;

       for(int i =0;i<N-1;i++){
        int m = min(dict[i].size(),dict[i+1].size());
        int j = 0;
        while(j<m && dict[i][j] == dict[i+1][j]) j++;
        int node1 = (int) (dict[i][j] - 'a'),node2 = (int)( dict[i+1][j] - 'a');
        mapper(node1,node2);
       }
        for(int i=0;i<K;i++) if(!vis[i]) dfs(i);
        
        while(!s.empty()){
            char c = s.top() + 'a';
            s.pop();
            ans.push_back(c);
        }
       return ans;
    }
};