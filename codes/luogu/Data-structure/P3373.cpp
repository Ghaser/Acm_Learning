#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define mod 571373
ll ans[maxn<<2],a[maxn<<2],tag[maxn<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}

void up(ll p){
    ans[p]=(ans[ls(p)]+ans[rs(p)])%mod;
}
void build(ll p,ll l,ll r){
    tag[p]=0;
    if(l==r){ans[p]=a[l];return;}
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    up(p);
}


int main(){



    return 0;
}