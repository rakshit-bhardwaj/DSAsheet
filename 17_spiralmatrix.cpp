#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0,right = matrix[0].size(),top = 0,bottom = matrix.size(),i,j;

        while(left<right && top < bottom){
            // top row 
            for(i=left;i<right;i++){
                ans.push_back(matrix[top][i]);
                cout<<matrix[top][i]<<" ";
            }
            top++;

            // rightmost column
            for(i=top;i<bottom;i++){
                ans.push_back(matrix[i][right-1]);
                cout<<matrix[i][right-1]<<" ";
            }
            right--;
            
            if(!(left < right && top < bottom)) break;

            // bottom row
            for(i=right-1;i>=left;i--){
                ans.push_back(matrix[bottom-1][i]);
                cout<<matrix[bottom-1][i]<<" ";
            }
            bottom--;

            // leftmost column
            for(i=bottom-1;i>=top;i--){
                ans.push_back(matrix[i][left]);
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }       
        return ans;
    }
};

int main (){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    vector<int> ans = obj.spiralOrder(matrix);
    return 0;
}