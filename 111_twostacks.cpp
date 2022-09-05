#include<bits/stdc++.h>
using namespace std;

class twostack{
    public:
    int arr[100];
    int s=0,e = 99;

    void push1(int x){
        if(s==e) {
            cout<<"overflow\n";
            return;
        }
        arr[s] = x;
        s++;
    }

    void push2(int x){
        if(s==e) {
            cout<<"overflow\n";
            return;
        }
        arr[e] = x;
        e--;
    }

    void pop1(){
        if(s==0) {
            cout<<"underflow\n";
            return;
        }
        s--;
    }
    void pop2(){
        if(s==99){
            cout<<"underflow\n";
            return;
        }
        e++;
    }

    void print1(){
        if(s==0){
            cout<<"stack1 is empty\n";
            return;
        }
        for(int i=0;i<s;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void print2(){
        if(e==99){
            cout<<"stack2 is empty\n";
            return;
        }
        for(int i=99;i>e;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main (){
    twostack s;
    s.push1(1);
    s.push1(2);
    s.push1(4);
    s.push1(3);
    s.print1();
    s.pop1();
    s.pop1();
    s.print1();
    s.push2(99);
    s.push2(96);
    s.push2(94);
    s.push2(97);
    s.print2();
    s.pop2();
    s.pop2();
    s.print2();

}