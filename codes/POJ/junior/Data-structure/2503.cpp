//字符串HASH(X)
//直接用map
//难点在于如何判断输入的停止位置
//空行
//真 水题
#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#define maxn 100005
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    map<string,string>trans;
    map<string,int>judge;
    char e[15],f[15],w[15];
    while(1){
        char a;
        int cnt=1;
        if((a=getchar())=='\n'){
            break;
        }
        else{
            e[0]=a;
            while(1){
                a=getchar();
                if(a==' '){
                    e[cnt]='\0';
                    break;
                }else{
                    e[cnt++]=a;
                }
            }
        }
        cin>>f;
        judge[f]=1;
        trans[f]=e;
        getchar();
    }
    while(cin>>w){
        if(judge[w]){
            cout<<trans[w]<<endl;
        }else{
            cout<<"eh"<<endl;
        }
    }
    return 0;
}