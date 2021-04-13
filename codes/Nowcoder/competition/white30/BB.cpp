#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;c=getchar();
    }
    while(c>='0'&&c<='9'){
        s=(s<<1)+(s<<3)+(c^48);c=getchar();
    }
    return f*s;
}
const int N=1555555;
int a[N],val[N],num[N];
void build(int p,int l,int r){
    if(l==r){
        val[p]=a[l];num[p]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    val[p]=max(val[p<<1],val[p<<1|1]);
    if(val[p<<1]==val[p<<1|1])num[p]=num[p<<1]+num[p<<1|1];
    else if(val[p<<1]>val[p<<1|1])num[p]=num[p<<1];
    else num[p]=num[p<<1|1];
}
inline void change(int p,int l,int r,int x,int k){
    if(l>x||r<x)return ;
    if(l==r){
        val[p]=k;num[p]=1;
        return ;
    }
    int mid=(l+r)>>1;
    change(p<<1,l,mid,x,k);
    change(p<<1|1,mid+1,r,x,k);
    val[p]=max(val[p<<1],val[p<<1|1]);
    if(val[p<<1]==val[p<<1|1])num[p]=num[p<<1]+num[p<<1|1];
    else if(val[p<<1]>val[p<<1|1])num[p]=num[p<<1];
    else num[p]=num[p<<1|1];
}
inline int querymaxn(int p,int l,int r,int L,int R){
    if(l>R||L>r)return 0;
    if(l>=L&&r<=R)return val[p];
    int mid=(l+r)>>1;
    return max(querymaxn(p<<1,l,mid,L,R),querymaxn(p<<1|1,mid+1,r,L,R));
}
int MAXN;
inline int query(int p,int l,int r,int L,int R){
    if(l>R||L>r)return 0;
    if(l>=L&&r<=R){
        if(val[p]==MAXN)return num[p];
        else return 0;
    }
    int mid=(l+r)>>1;
    return query(p<<1,l,mid,L,R)+query(p<<1|1,mid+1,r,L,R);
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,1,n);
    while(m--){
        char s[10];scanf("%s",&s);
        if(s[0]=='A'){
            int l=read(),r=read();MAXN=querymaxn(1,1,n,l,r);
            printf("%d %d\n",MAXN,query(1,1,n,l,r));
        }
        else{
            int x=read(),k=read();
            change(1,1,n,x,k);
        }
    }
    return 0;
}