#include<bits/stdc++.h>
using namespace std;
int n,amap[305][305],vis[305][305],xx,yy,ans[305][305];
struct n{
    int x,y,t;
}b[50005];
struct node
{
    int x,y;
}a;
queue<node> q;
int mx[5]={0,0,0,1,-1},my[5]={0,1,-1,0,0};
int main(){
    cin>>n;
    memset(amap,-1,sizeof(amap));
    for(int i=1;i<=n;i++){
        cin>>b[i].x>>b[i].y>>b[i].t;
        for(int j=0;j<5;j++){
            xx=b[i].x+mx[j];
            yy=b[i].y+my[j];
            if(xx>=0&&yy>=0&&(amap[xx][yy]==-1||amap[xx][yy]>b[i].t))
            amap[xx][yy]=b[i].t;
        }
    }
    vis[0][0]=1;
    q.push((node){0,0});
    while(!q.empty()){
        a=q.front();
        q.pop();
        int s=ans[a.x][a.y]+1;
        if(amap[a.x][a.y]==-1){
            cout<<s-1;
            return 0;
        }
        for(int i=1;i<=4;i++){
            int xxx=a.x+mx[i],yyy=a.y+my[i];
            if(xxx>=0&&yyy>=0&&vis[xxx][yyy]==0&&(s<amap[xxx][yyy]||amap[xxx][yyy]==-1)){
                q.push((node){xxx,yyy});
                ans[xxx][yyy]=s;
                vis[xxx][yyy]=1;
            }
        }
    }
    cout<<-1;
    return 0;
}