#include<bits/stdc++.h>
using namespace std;
//读入一个字符串，判断在某个地方加上a后是否为非回文串
//如果是，输出YES，并输出一个加上a的非回文串
//除全a串外，加a都可变成非回文串？

bool judge(string x){
    for(int i=0;i<x.length();i++){
            if(x[i]!='a'){
                break;
            }
            if(i==x.length()-1){
                return 1;
            }
        }
    return 0;
}


int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        if(judge(a)){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            if(!judge(a+'a')){
                cout<<a+'a'<<endl;
            }else if(!judge('a'+a)){
                cout<<'a'+a<<endl;
            }
        }

    }


    return 0;
}