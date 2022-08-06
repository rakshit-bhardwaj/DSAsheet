#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> stalls,int x,int c){
    c--; int prev = 0;
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - stalls[prev] >= x){
            prev = i;
            c--;
            if(!c) return true;
        }
    }
    return false;
}

int lmd(int n,int c, vector<long long> stalls){
    int s = 1,e = stalls[n-1] -stalls[0],m,ans=INT_MIN;
    while(s<=e){
        m = (s+e) >> 1;
        if(check(stalls,m,c)){
            ans = max(ans,m);
            s = m + 1;
        } else e = m - 1; 
    }
    return ans;
}

int main () {
    int t,n,c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        vector<long long> stalls(n);
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        sort(stalls.begin(),stalls.end());
        cout<<lmd(n,c,stalls)<<endl;
    }
    return 0;
}
/*test case 
2
5 3
1 
2
4
8
9
2 2
0
1
*/