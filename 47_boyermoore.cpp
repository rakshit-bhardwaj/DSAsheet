#include<bits/stdc++.h>
using namespace std;

int boyermoore(string t,string p){
    int in=p.size()-1,i,j;
    map<char,int> badmatch;
    for(int i=0;i<t.size();i++){
        int val = max(1,int(p.size() - i - 1));
        badmatch[p[i]]=val;
    }
    while(in<t.size()){
        cout<<"checking pattern from "<<in<<endl;
        i = in;
        j = p.size()-1;
        while(i>=in - p.size()+1){
            auto it = find(p.begin(),p.end(),t[i]);
            if(t[i]!=p[j]){
                if(it==p.end()){
                    in+=j+1;
                }
                else{
                    in += badmatch[t[i]];
                    j =  p.size() - 1;
                }
                break;
            }
            if(j==0) return i;
            i--;
            j--;
        }
    }
    return -1;
}

int main () {
    string t = "this is a test";
    string p = "test";
    cout<<boyermoore(t,p);
    return 0;
}