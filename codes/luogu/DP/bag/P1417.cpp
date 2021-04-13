#include<bits/stdc++.h>
using namespace std;
#define ll long long
//先按照优先级排序后进行dp
//优先级的判定:x.c*y.b<y.c*x.b;
//本题唯一的难点
ll n,T,dp[100005],ans=0;
struct food{
    ll a,b,c;
}f[55];
bool cmp(food x,food y){
    return x.c*y.b<y.c*x.b;
}
int main(){
    cin>>T>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i].a;
    }
    for(int i=1;i<=n;i++){
        cin>>f[i].b;
    }
    for(int i=1;i<=n;i++){
        cin>>f[i].c;
    }
    sort(f+1,f+1+n,cmp);
    for(int i=1;i<=n;i++){
        for(int j=T;j-f[i].c>=0;j--){
            dp[j]=max(dp[j],dp[j-f[i].c]+f[i].a-j*f[i].b);
        }
    }
    for(int i=1;i<=T;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;



    return 0;
}