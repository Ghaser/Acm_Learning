#include<bits/stdc++.h>
using namespace std;
int n,m,t,pre,p[100005],judge[100005],mq[100005];
struct ordering{
    int ts,id;
}o[100005];
//暴力算法，只能混分
bool cmp(ordering a,ordering b){
    if(a.ts==b.ts){
        return a.id<b.id;
    }
    return a.ts<b.ts;
}

int main(){
    ios::sync_with_stdio(0);
    memset(p,0,sizeof(p));
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++){
        cin>>o[i].ts>>o[i].id;
    }
    pre=1;
    sort(o+1,o+m+1,cmp);//将订单按时间排序

    for(int i=1;i<=t;i++){//以时间为单位进行遍历
        for(int j=pre;j<=m;j++){//外卖订单
            if(o[j].ts>i){
                pre=j;
                break;
            }
            if(o[j].ts==i){
                p[o[j].id]+=3;//后面减一群体覆盖
            }
        }
       
        for(int j=1;j<=n;j++){//遍历门店
            if(p[j]>0)p[j]--;
            if(p[j]>5&&judge[j]==0){
                judge[j]=1;//加入优先缓存
            }
            if(p[j]<=3&&judge[j]==1){
                judge[j]=0;//推出优先缓存
            }
        }
    }   
    int ans=0;
    for(int i=1;i<=n;i++){
        if(judge[i]==1){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//1 2 3 5 6 6