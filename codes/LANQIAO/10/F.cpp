#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,a[100005],d,ans,as=-99999999,ad;
//暴力层序遍历二叉树?
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //通过n先确定二叉树的深度
    ll t=n;
    while(t){
        t/=2;
        d++;
    }
    for(int i=1;i<=d;i++){//二叉树的层序遍历
        ans=0;
        for(int j=(1<<(i-1));j<(1<<i);j++){
             ans+=a[j];
        }
        if(ans>as){
            as=ans;
            ad=i;
        }
    }
    cout<<ad<<endl;

    return 0;
}