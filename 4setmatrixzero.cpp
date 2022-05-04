#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size(), i, j, t;
    vector<pair<int, int>> zind;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            
            if (matrix[i][j] == 0)
            {
                zind.push_back(make_pair(i,j));
            }
        }
    }
    for (pair<int, int> z : zind)
    {
        
        i = z.first;
        j = z.second;
        
        if (i > 0)
        {
            t = i;
            while (t != 0)
            {   
                matrix[--t][j] = 0;
            }
            
        }
        if (i < n - 1)
        {
            t = i;
            while (t < n-1)
            {   
                matrix[++t][j] = 0;
            }
        }
        
        
        if (j > 0)
        {
            t = j;
            while (t != 0)
            {
                matrix[i][--t] = 0;
            }
        }
        if (j < m - 1)
        {
            t = j;
            while (t < m-1)
            {
                matrix[i][++t] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
        };

    setZeroes(matrix);
    cout<<"[";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j];
            if (j != matrix[0].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != matrix.size() - 1)
            cout << ",";
    }
    cout<<"]";
    return 0;
}