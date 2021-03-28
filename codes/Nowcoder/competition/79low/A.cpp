#include<bits/stdc++.h>
using namespace std;
struct node{
    int r,co;
}a[1000005];
bool cmp(node x,node y){
    if(x.r==y.r){
        return x.co>y.co;
    }
    return x.r>y.r;
}

int n,maxe=-1,last=-1,ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a[i].r=t;//范围
        a[i].co=i;//颜色,次数
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(a[i].co>maxe&&a[i].r!=last){
            ans++;
            maxe=max(maxe,a[i].co);
            last=a[i].r;
        }
    }
    cout<<ans;
    return 0;
}