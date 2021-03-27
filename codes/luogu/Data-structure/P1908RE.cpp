#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//使用树状数组实现逆序对的求解
ll c[500005],n,ans;
ll lowbit(ll x){
    return x&(-x);
}
ll sum(ll i){
    ll s=0;
    while(i>=1){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
void add(ll i,ll v){
    while(i<=n){
        c[i]+=v;
        i+=lowbit(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    cout<<lowbit(4)<<endl;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        add(a,1);
        ans+=(sum(n)-sum(a));
        cout<<ans<<endl;
    }
    cout<<ans;


    return 0;
}
//c[5]=1; 5 c[6]=1 101 sum[6]-sum[5]=
//c[4]=1; 4 100 
//sum(n)  c[n]+c[n-lowbit(n)]+……+
//sum(6)  c[6]+c[4]
//sum(5)  c[5]+c[4]
//sum(4)  c[4]