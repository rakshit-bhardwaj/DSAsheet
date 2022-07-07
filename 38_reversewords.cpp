#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        int i =0;
        int j = s.size()-1;
        while(s[j]==' '){
            s.pop_back();
            j--;
        }
        while(i<s.size()){
            while(s[i]==' ' && i<s.size()){
                i++;
            }
            string str;
            while(s[i]!=' ' && i<s.size()){
                str.push_back(s[i]);
                i++;
            }
            words.push(str);
        }
        string ans;
        while(!words.empty()){
            string temp = words.top();
            words.pop();
            ans.append(temp);
            ans.append(" ");
        }
        ans.pop_back();
        return ans;
    }
};

int main () {
    Solution obj;
    string s = " hello world ";
    cout<<obj.reverseWords(s);
    return 0;
}