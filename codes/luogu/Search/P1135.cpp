//尝试使用BFS，广度优先搜索
#include<bits/stdc++.h>
using namespace std;
int n,a,b,x[205];
bool l[205];//通过数列来判定是否到达过这个节点
struct node{
    int id,ans;
}y;
queue<node> q;//队列q
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    l[a]=1;//应该要将初始化值设置为1，代表初始点已经访问过了
    q.push((node){a,0});//让起始点入队
    while(q.size()){
        y=q.front();
        q.pop();
        if(y.id==b)break;
        if(y.id+x[y.id]<=n&&!l[y.id+x[y.id]]){
            q.push((node){y.id+x[y.id],y.ans+1});//访问相邻的点
            l[y.id+x[y.id]]=1;//更新数组
        }
        if(y.id-x[y.id]<=n&&!l[y.id-x[y.id]]){
            q.push((node){y.id-x[y.id],y.ans+1});
            l[y.id-x[y.id]]=1;//更新数组
        }
    }
    if(y.id==b)cout<<y.ans;
    else cout<<-1;
    return 0;
}