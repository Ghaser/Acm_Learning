#include<bits/stdc++.h>
using namespace std;
//贪心算法？
//注意一个小球可以被重复取出(反复横跳)
//关键在于b数组 按照b数组初始顺序来设置
#define ll long long
struct Hole{
    ll id,w;
    /*bool operator < (const Hole& opt) const{
        return w<opt.w;
    }//重载运算符*/
}h[2005];
ll n,m,a[2005],b[2005],vis[2005];


int main(){
    cin>>n>>m;
    ll top=0,ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(!vis[b[i]]){
            vis[b[i]]=1;
            h[++top].id=b[i];//编号
            h[++top].w=a[b[i]];//重量
        }
    }
    for(int i=1;i<=n;i++){
        
    }
    for(int i=1;i<=m;i++){//开始操作
        for(int j=1;j<=top;j++){
            if(b[i]==h[j].id){
                Hole temp=h[j];
                for(int k=j;k>=2;k--){
                    h[k]=h[k-1];
                }
                h[1]=temp;
                break;
            }else{
                ans+=h[j].w;//计算答案
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}