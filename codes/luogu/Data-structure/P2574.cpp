#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 200005
//线段树 or 树状数组
//树状数组无法同时实现成段更新及成段求和，所以考虑线段树
//按字符读入数据
//通过^异或来变换 0 1
ll n,m;
ll tag[maxn<<2],ans[maxn<<2],a[maxn<<2];
char s[maxn];
ll ls(ll p){return p<<1;};
ll rs(ll p){return p<<1|1;};

void up(ll p){
    ans[p]=ans[ls(p)]+ans[rs(p)];
}

void build(ll p,ll l ,ll r){
    tag[p]=0;
    if(l==r){ans[p]=a[l];return; }
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    up(p);
}//建树

void lazy(ll p,ll l,ll r){
    ll len=r-l+1;
    if(tag[p]){
        tag[ls(p)]^=1;
        tag[rs(p)]^=1;
        ans[ls(p)]=(len-(len>>1))-ans[ls(p)];
        ans[rs(p)]=(len>>1)-ans[rs(p)];
        tag[p]=0;
    }
}

void update(ll p,ll l,ll r,ll x, ll y){
    
    if(x<=l&&y>=r){
        ans[p]=r-l+1-ans[p];
        tag[p]^=1;
        return;
    }
    lazy(p,l,r);
    ll mid=(l+r)>>1;
    if(x<=mid)update(ls(p),l,mid,x,y);
    if(y>mid)update(rs(p),mid+1,r,x,y);
    up(p);
}

ll query(ll x,ll y,ll l,ll r,ll p){
    ll res=0;
    if(x<=l&&y>=r)return ans[p];
    lazy(p,l,r);
    ll mid=(l+r)>>1;
    if(x<=mid)res+=query(x,y,l,mid,ls(p));
    if(y>mid)res+=query(x,y,mid+1,r,rs(p));
    return res;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        a[i]=s[i]-'0';
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int a1,a2,a3;
        cin>>a1;
        if(a1==0){
            cin>>a2>>a3;
            update(1,1,n,a2,a3);
        }else if(a1==1){
            cin>>a2>>a3;
            cout<<query(a2,a3,1,n,1)<<endl;
        }
    }
    return 0;
}