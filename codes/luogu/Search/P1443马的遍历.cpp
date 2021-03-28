//BFS算法基本思路
//首先创建一个visit数组和队列q，分别判断位置是否已经访问
//以及未访问过的点入队，并且初始化和清空
//让起点start入队，并且使该点重置为1
//然后通过while(q.size())进行搜索操作
#include<bits/stdc++.h>
using namespace std;
int n,m,xx,yy,visit[405][405],walk[405][405];
int mx[8]={2,-2,2,-2,-1,1,-1,1},my[8]={1,1,-1,-1,2,2,-2,-2};//马共有十六种方向可以行走
struct node{
    int x,y;
}a;
queue<node> q;
int main(){
    cin>>n>>m>>xx>>yy;
    memset(visit,0,sizeof(visit));
    memset(walk,-1,sizeof(walk));
    q.push((node){xx,yy});
    walk[xx][yy]=0;
    visit[xx][yy]=1;
    while(q.size()){
        a=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int xxx=a.x+mx[i];
            int yyy=a.y+my[i];
            if(xxx<1||xxx>n||yyy<1||yyy>m||visit[xxx][yyy]){}
            else{
            visit[xxx][yyy]=1;
            q.push((node){xxx,yyy});
            walk[xxx][yyy]=walk[a.x][a.y]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d",walk[i][j]);//用-来进行左对齐
        }
        cout<<endl;
    }
    return 0;
}