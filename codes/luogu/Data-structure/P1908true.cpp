#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//无法直接使用树状数组
//需要进行离散化
ll c[500005],r[500005],n,ans;
struct point{
    int num,val;
}a[500005];
bool cmp(point x,point y){
    if(x.val==y.val){
        return x.num<y.num;
    }
    return x.val<y.val;
}

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
    for(int i=1;i<=n;i++){
        cin>>a[i].val;;
        a[i].num=i;
    }
    sort(a+1,a+1+n,cmp);//排序方便进行离散化
    for(int i=1;i<=n;i++){
        r[a[i].num]=i;
    }
    for(int i=1;i<=n;i++){
        add(r[i],1);
        ans+=sum(n)-sum(r[i]);
    }
    cout<<ans;


    return 0;
}