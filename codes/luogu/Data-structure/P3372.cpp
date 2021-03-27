#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define ll long long
ll tag[maxn<<2],ans[maxn<<2],a[maxn<<2],n,m;


ll ls(ll p){return p<<1;};
ll rs(ll p){return p<<1|1;};

void pushe(ll p){//维护函数，建立父子节点间的联系
    ans[p]=ans[ls(p)]+ans[rs(p)];
    //针对求和的维护函数
}
void build(ll p,ll l,ll r){
    tag[p]=0;
    if(l==r){ans[p]=a[l];return;};
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    pushe(p);
}

void updateOne(ll p,ll l,ll r,ll k){
    tag[p]=tag[p]+k;
    ans[p]=ans[p]+k*(r-l+1);
}

void lazy(ll p, ll l,ll r){
    ll mid=(l+r)>>1;
    updateOne(ls(p),l,mid,tag[p]);
    updateOne(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}
void update(ll x,ll y,ll l,ll r,ll p,ll k)
{
    if(x<=l&&r<=y)
    {
        ans[p]+=k*(r-l+1);
        tag[p]+=k;
        return ;
    }
    lazy(p,l,r);
    ll mid=(l+r)>>1;
    if(x<=mid)update(x,y,l,mid,ls(p),k);
    if(y>mid) update(x,y,mid+1,r,rs(p),k);
    pushe(p);
}
ll query(ll x,ll y,ll l,ll r,ll p){
    ll res=0;
    if(x<=l&&y>=r)return ans[p];
    ll mid=(l+r)>>1;
    lazy(p,l,r);
    if(x<=mid)res+=query(x,y,l,mid,ls(p));
    if(y>mid)res+=query(x,y,mid+1,r,rs(p));
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a1,a2,a3,a4;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        cin>>a1;
        if(a1==1){
            cin>>a2>>a3>>a4;
            update(a2,a3,1,n,1,a4);
        }else if(a1==2){
            cin>>a2>>a3;
            cout<<query(a2,a3,1,n,1)<<endl;
;        }   
    }
    return 0;
}