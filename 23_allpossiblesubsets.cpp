#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> arr,int r,vector<int> ch,int i,int index){
    // cout<<"index = "<<index<<" i = "<<i<<endl;
    if(index==r){
        cout<<"[";
        for(int j=0;j<r;j++){
            cout<<ch[j]<<" ";
        }cout<<"] ";
        return;
    }
   
    if(i>=arr.size()) return;

    ch[index] = arr[i];
    solution(arr,r,ch,i+1,index+1);
    solution(arr,r,ch,i+1,index);

}



int main () {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ch(3,0);
    solution(arr,3,ch,0,0);
    return 0;
}