#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define maxn 100005
#define mod 99999997
//联想到逆序对
//相对逆序对？
//新建序列即可实现相对逆序对
struct point{
    ll num,val;
}a[maxn],b[maxn];
ll n,ans=0;
ll a1[maxn],b1[maxn],p[maxn],c[maxn];
bool cmp(point x,point y){
    return x.val<y.val;
}
ll lowbit(ll x){
    return x&(-x);
}


void add(ll i,ll v){
    while(i<=n){
        c[i]+=v;
        c[i]%=mod;
        i+=lowbit(i);
    }
}
ll sum(ll i){
    ll s=0;
    while(i){
        s+=c[i];
        s%=mod;
        i-=lowbit(i);
    }
    return s;
}

int main(){
    //--------读入数据--------
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].num=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].val;
        b[i].num=i;
    }
    //-------离散相对化-------
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+1+n,cmp);//排序方便进行离散化
    /*for(int i=1;i<=n;i++){
        a1[a[i].num]=i;
        b1[b[i].num]=i;
    }*/
    for(int i=1;i<=n;i++){
        p[a[i].num]=b[i].num;
    }
    //------树状数组求解----
    for(int i=1;i<=n;i++){
        add(p[i],1);
        ans+=i-sum(p[i]);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}