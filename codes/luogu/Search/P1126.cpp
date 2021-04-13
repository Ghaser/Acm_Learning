#include<bits/stdc++.h>
using namespace std;
//本题的难点在于机器人有面朝方向
//想要向其他方向走需要先进行转向
//考虑BFS 广度优先搜索
// 0 E 1 S 2 W 3 N
int mx[4]={0,1,0,-1},my[4]={-1,0,1,0};

//东 南 西 北
struct w{
    int x,y,dir,t;//当前节点的横坐标、纵坐标以及其朝向
};
int n,m,sx,sy,ex,ey;
string d;
int visit[55][55][5],amap[55][55];
queue<w> q;
int main(){
    memset(visit,0,sizeof(visit));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int temp;
            cin>>temp;
            if(temp==1){
                amap[i-1][j]=1;
                amap[i][j-1]=1;
                amap[i-1][j-1]=1;
                amap[i][j]=1;
            }//将障碍物地图转化为行走地图
    
        }
    }
    cin>>sx>>sy>>ex>>ey>>d;
    if(d=="E"){
        q.push(w{sx,sy,0,0});
    }else if(d=="S"){
        q.push(w{sx,sy,1,0});
    }else if(d=="W"){
        q.push(w{sx,sy,2,0});
    }else if(d=="N"){
        q.push(w{sx,sy,3,0});
    }
    while(!q.empty()){
        w a;
        a=q.front();
        q.pop();
        if(a.x==ex&&a.y==ey){
            cout<<a.t;
            exit(0);
        }
        if(visit[a.x][a.y][a.dir]){
            continue;
        }
        visit[a.x][a.y][a.dir]=1;
        //转向
        
        q.push(w{a.x,a.y,(a.dir+4+1)%4,a.t+1});
        q.push(w{a.x,a.y,(a.dir+4-1)%4,a.t+1});
        //前进n
        for(int i=1;i<=3;i++){
            int xx=a.x+mx[a.dir]*i;
            int yy=a.y+my[a.dir]*i;
            if(xx<1||yy<1||xx>=n||yy>=m||amap[xx][yy]){
                break;//这里注意是break，碰到障碍物一个尚且走不了，更别说以上了
            }else{
                q.push(w{xx,yy,a.dir,a.t+1});
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
/*
if(a.x==ex&&a.y==ey){
            cout<<a.t;
            return 0;
        }

        if(a.dir==1){//面向东边
            for(int i=0;i<=2;i++){
                int xx=a.x+walk[i];
                int yy=a.y;
                if(xx<1||xx>n||visit[xx][yy]){}
                else{
                    visit[xx][yy]=1;
                    q.push({xx,yy,1,a.t+1});
                }
            }
            q.push({a.x,a.y,2,a.t+1});
            q.push({a.x,a.y,4,a.t+1});
        }
        if(a.dir==2){
            for(int i=0;i<=2;i++){
                int xx=a.x;
                int yy=a.y+walk[i];
                if(yy<1||yy>n||visit[xx][yy]){}
                else{
                    visit[xx][yy]=1;
                    q.push({xx,yy,2,a.t+1});
                }
            }
            q.push({a.x,a.y,1,a.t+1});
            q.push({a.x,a.y,3,a.t+1});
        }
        if(a.dir==3){
            for(int i=0;i<=2;i++){
                int xx=a.x+walk[i];
                int yy=a.y;
                if(xx<1||xx>n||visit[xx][yy]){}
                else{
                    visit[xx][yy]=1;
                    q.push({xx,yy,3,a.t+1});
                }
            }
            q.push({a.x,a.y,2,a.t+1});
            q.push({a.x,a.y,4,a.t+1});
        }
        if(a.dir==4){
            for(int i=0;i<=2;i++){
                int xx=a.x;
                int yy=a.y+walk[i];
                if(yy<1||yy>n||visit[xx][yy]){}
                else{
                    visit[xx][yy]=1;
                    q.push({xx,yy,4,a.t+1});
                }
            }
            q.push({a.x,a.y,1,a.t+1});
            q.push({a.x,a.y,3,a.t+1});
        }

*/