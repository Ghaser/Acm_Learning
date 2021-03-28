#include<bits/stdc++.h>
using namespace std;
int amap[6][6],already[6][6];//后者为对走过的点的标记
int r,c,t,sx,sy,fx,fy,t1,t2,ans=0;
int mx[4]={0,0,-1,1},my[4]={1,-1,0,0};
void dfs(int x,int y){
    if(x==fx&&y==fy){
        ans++;
        return;
    }
    else{
        for(int i=0;i<=3;i++){//运用到了回溯法，如果走不过去就回到上一步
            if(already[x+mx[i]][y+my[i]]==0&&amap[x+mx[i]][y+my[i]]==1){//保障不能往回走或者走到障碍
                already[x][y]=1;
                dfs(x+mx[i],y+my[i]);
                already[x][y]=0;
            }
        }
    }

}


int main(){
    
    cin>>r>>c>>t>>sx>>sy>>fx>>fy;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            amap[i][j]=1;
        }
    }
    for(int i=0;i<t;i++){
        cin>>t1>>t2;
        amap[t1][t2]=0;
    }
    dfs(sx,sy);
    cout<<ans<<endl;
    return 0;
}