#include<bits/stdc++.h>
using namespace std;


int findPages(int A[], int N, int M) {
    int maxp = INT_MAX;
    int s = INT_MAX;
    int e = 0;
    int m,stu=0,cr,j,mx;
    bool c = true;
    for(int i=0;i<N;i++){
        if(A[i]<s) s = A[i];
        e+=A[i];
    }
    //cout<<"s = "<<s<<endl;
    //cout<<"e = "<<e<<endl;
    
    while(s<=e){
        int m = (s+e)/2;
        cout<<"xxxxxxxxxxxxxxxxxxx\n";
        cout<<"max pages allowed -> "<<m<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxx\n";
        stu=0;cr = 0;j = 0;mx=0;c = true;
        while(j<N){
            cr+=A[j];
            //cout<<A[j]<<" books given to student "<<stu<<endl;
            j++;
            if(j == N && stu == M-1){
                mx = max(mx,cr);
                break;
            }
            if(cr + A[j]>m){
                mx = max(mx,cr);
                cout<<cr<<" books allocated to student "<<stu<<endl;
                stu++;
                cr=0;
                if(stu == M){
                    cout<<"xxxxxxxxxxxxxxxxxxx\n";
                    cout<<"students exceeded\n";
                    cout<<"xxxxxxxxxxxxxxxxxxx\n";
                    s = m+1;
                    //cout<<"students exceed given count updating 's' to "<<m+1<<endl;
                    c=false;
                    break;
                }
            }
            //cout<<"xxxxxxxxxxxxxxxxxxx\n";
        }
        if(c){
            if((stu == M -1)){
                maxp = min(maxp,mx);
                //cout<<"--------------------\n";
                cout<<"max pages updated to "<<maxp<<endl;
                //cout<<"--------------------\n";
            }
            e = m-1;
            //cout<<"students exceed given count updatig 'e' to "<<m-1<<endl;
        }
        
    }

    return maxp;
}

int main () {
    int A[] = {13, 31, 37, 45, 46, 54, 55, 63, 73, 84, 85};
    int m = 9;
    int n = 11;

    cout<<findPages(A,n,m);
}