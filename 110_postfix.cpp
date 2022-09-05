#include<bits/stdc++.h>
using namespace std;

int postfix(string eval){
    stack<int> s;
    int n = eval.size();
    for(int i = 0;i<n;i++){
        int num = 0;
        if(eval[i]==' ') continue;
        if(eval[i]=='+' || eval[i]=='-' || eval[i]=='*' || eval[i] =='/'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch(eval[i]){
                case '+':
                s.push(a+b);
                break;
                case '-':
                s.push(b-a);
                break;
                case '*':
                s.push(b*a);
                break;
                case '/':
                s.push(b/a);
            }
            continue;
        }
        while(eval[i]>= '0' && eval[i]<='9'){
            num = num*10 + (eval[i]-'0');
            i++;
        }
        s.push(num);
    }
    return s.top();
}

int main () {
    string eval = "2 3 1 * + 9 -";
    cout<<postfix(eval);
    return 0;
}