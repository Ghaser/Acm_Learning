#include<bits/stdc++.h>
using namespace std;


int main(){
    //stl::stack 成员函数 .top()为获取栈顶元素  .pop()为弹出栈顶   .push(i)为将i推入栈
    stack<int>stk;//储存当前栈的情况
    stack<int>stkmax;//储存当前栈内最值

    int n;
    cin>>n;
    string s;

    for (int i=0;i<n;++i){
        cin>>s;
        if (s=="queryMax"){
            if (stkmax.empty())
                cout<<"0"<<endl;
            else 
                cout<<stkmax.top()<<endl;
        }
        else if (s=="pop"){
            int f=stk.top();
            stk.pop();
            if (f==stkmax.top())
                stkmax.pop();
        }
        else if (s=="push"){
            int val;
            cin>>val;
            stk.push(val);
            int temp=stkmax.top();
            cout<<temp;
            if (val>temp)
                stkmax.push(val);
        }
    }    
    fclose(stdin);fclose(stdout);
    return 0;
}