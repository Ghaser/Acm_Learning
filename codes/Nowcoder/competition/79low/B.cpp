#include<bits/stdc++.h>
using namespace std;
//a 四种选择 变为b *3 *1/3  *5/3 *3/5
//深度优先
#define ll long long
int c1[4]={3,1,5,3},c2[4]={1,3,3,5};

ll a,b,ans,a1,b1;
void dfs(ll t){
    if(a==b){
        ans+=t;
        cout<<'a'<<endl;
        return;
    }
    for(int i=0;i<4;i++){
        if(a%c2[i]==0){
            a*=c1[i];
            a/=c2[i];
            dfs(t+1);
            a/=c1[i];
            a*=c2[i];
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    ll n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        dfs(0);
    }
    cout<<ans<<endl;

    return 0;
}