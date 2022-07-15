#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int l = 0,r = matrix.size() - 1,t,b;
        while( l < r ){
            for(int i=0;i<(r-l);i++){
                t = l;b = r;
                int topleft = matrix[t][l + i];
                matrix[t][l + i] = matrix[b - i][l];
                matrix[b - i][l] = matrix[b][r - i];
                matrix[b][r - i] = matrix[t + i][r];
                matrix[t + i][r] = topleft;
            }
            l+=1;
            r-=1;
        }
    }
};