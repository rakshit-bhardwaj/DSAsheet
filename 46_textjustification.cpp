#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int spaces,extra;
        int i=0,j;
        while(i<words.size()){
            extra = 0;
            vector<string> cur;
            cur.push_back(words[i]);
            int count = 0;
            int rem = maxWidth - words[i].size();
            cout<<"word = "<<words[i]<<" , ";
            cout<<"remaining space = "<<rem<<endl;
            for(j = i+1;j<words.size();j++){
                if(rem<=0) break;
                if(words[j].size()<=rem-1){
                    count ++;
                    cur.push_back(words[j]);
                    rem = rem - words[j].size() -1;
                    cout<<"word = "<<words[j]<<" , ";
                    cout<<"remaining space = "<<rem<<endl;
                } else break;
            }
            
            i = j;
            
            
            string temp;
            if(count == 0){
                temp = cur[0];
                int t = maxWidth - cur[0].size();
                while(t--){
                    temp.push_back(' ');
                }
            }
            else {
                if((rem+count)%count==0){
                spaces = (rem+count)/count;
            } else{
                spaces = (rem+count)/count;
                extra = rem%count;
            }
            
            
            for(int j = 0;j<cur.size();j++){
                temp.append(cur[j]);
                if(i>=words.size() ){
                    if(j!=cur.size()-1)
                    temp.push_back(' ');
                    else if(j==cur.size()-1){
                        int t = maxWidth - temp.size();
                        while(t--){
                            temp.push_back(' ');
                        }
                    }
                }
                else {
                    if(j!=cur.size()-1){
                    int t = spaces;
                    while(t--){
                        temp.push_back(' ');
                    }
                    if(extra>0){
                        temp.push_back(' ');
                        extra--;
                    }
                }
                }
                
            }
            }
            
            cout<<endl<<"count of words = "<<count<<" remaining space = "<<rem<<endl;
            cout<<"equal spaces = "<<spaces<<" extra spaces = "<<extra<<endl;
            cout<<temp<<endl;
            cout<<"size of temp = "<<temp.size()<<endl;
            cout<<"------------------------------"<<endl;
            ans.push_back(temp);
        }
        return ans;
    }
};

int main () {
    Solution obj;
    vector<string> s = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    vector<string> ans = obj.fullJustify(s,maxWidth);
    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}