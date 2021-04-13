#include<bits/stdc++.h>
using namespace std;
//并查集 yyds！！ 给他突然发出vbg
//暴力枚举必然超时
//并查集
//题目逻辑：
//一个数一旦被使用过，其父亲就是其+1
//如果反复被使用过，则使用并查缉便可以查找其祖先
// 可以使用树状数组
int n,a[100005],x;
int find(int x){
    if(a[x]==x){
        return x;
    }
    a[x]=find(a[x]);
    return a[x];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){a[i]=i;}//并查集初始化，自己作为自己的父节点
    for(int i=1;i<=n;i++){
        cin>>x;
        x=find(x);
        cout<<x<<' ';
        a[x]=x+1;
    }
    return 0;
}
//a 
//1 2 3 4 5 初始化
//1 3 3 4 5
//2 3 3 4 5