#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200005
//显然运用线段树
ll n,m,w[maxn<<2],ans[maxn<<2],num[maxn<<2];
ll Maxn;//num数组用以记录最大值数的个数
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void up(ll p){
    ans[p]=max(ans[ls(p)],ans[rs(p)]);
}
void build(ll p,ll l,ll r){
    if(l==r){ans[p]=w[l];num[p]=1;return;};//叶子节点，进行赋值
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    up(p);//递归之后通过pushe函数来维护父子结点的关系
    //魔改线段树，同时对num进行统计
    if(ans[ls(p)]==ans[rs(p)])num[p]=num[ls(p)]+num[rs(p)];//当左子树等于右子树时
    else if(ans[ls(p)]>ans[rs(p)])num[p]=num[ls(p)];//当两子树值不同时，便取值更大子树最大值的数量
    else num[p]=num[rs(p)];
}
void update(ll p,ll l,ll r,ll x,ll k){
    if(l>x||r<x)return;//如果输入的x超出边界
    if(l==r){
        ans[p]=k;
        num[p]=1;
        return;
    }//遍历到单个节点时
    int mid=(l+r)>>1;
    update(ls(p),l,mid,x,k);
    update(rs(p),mid+1,r,x,k);
    up(p);
    //魔改线段树，同时对num进行统计
    if(ans[ls(p)]==ans[rs(p)])num[p]=num[ls(p)]+num[rs(p)];//当左子树等于右子树时
    else if(ans[ls(p)]>ans[rs(p)])num[p]=num[ls(p)];//当两子树值不同时，便取值更大子树最大值的数量
    else num[p]=num[rs(p)];
}
ll querymaxn(ll p,ll l,ll r,ll x,ll y){
    if(l>y||x>r)return 0;//范围越界
    if(l>=x&&y>=r)return ans[p];//完全覆盖
    ll mid=(l+r)>>1;
    return max(querymaxn(ls(p),l,mid,x,y),querymaxn(rs(p),mid+1,r,x,y));   
}//针对最大值的查询

ll querynum(ll p,ll l,ll r,ll x,ll y){
    if(l>y||x>r)return 0;
    if(l>=x&&y>=r){
        if(ans[p]==Maxn)return num[p];
        else return 0;//不是最大值就不计入统计
    }
    ll mid=(l+r)>>1;
    return querynum(ls(p),l,mid,x,y)+querynum(rs(p),mid+1,r,x,y);
}//针对数量的查询

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    build(1,1,n);
    while(m--){
        string s;
        cin>>s;
        if(s[0]=='A'){
            ll x,y;
            cin>>x>>y;
            Maxn=querymaxn(1,1,n,x,y);
            cout<<Maxn<<' '<<querynum(1,1,n,x,y)<<endl;
        }//判断首字母就可
        else{
            ll x,k;
            cin>>x>>k;
            update(1,1,n,x,k);
        }
    }
    
    
    return 0;
}