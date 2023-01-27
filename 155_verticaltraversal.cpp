#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> ans;
    map<int, vector<pair<int, int>>> mapo;

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);
        for (auto x : mapo)
        {
            sort(x.second.begin(), x.second.end(), [](pair<int, int> &left, pair<int, int> &right)
                 { if(left.second == right.second) return left.first < right.first;
                    return left.second < right.second; 
                    });
                vector<int> temp;
            for(auto y : x.second){
                temp.push_back(y.first);
            }
            ans.push_back(temp);
        }
        return ans;
    }

    void dfs(TreeNode *root, int row, int col)
    {
        if (root == NULL)
            return;
        dfs(root->left, row + 1, col - 1);
        if (mapo.find(col) != mapo.end())
            mapo[col].push_back({root->val, row});
        else
        {
            vector<pair<int, int>> temp;
            temp.push_back({root->val, row});
            mapo[col] = temp;
        }
        dfs(root->right, row + 1, col + 1);
    }
};