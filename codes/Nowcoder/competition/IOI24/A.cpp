#include<bits/stdc++.h>
using namespace std;
int a[64],b[64],c[64];

int main(){
    int x,y,cnt1=0,cnt2=0;
    cin>>x>>y;
    while(x!=0){
        a[++cnt1]=x%2;
        x/=2;
    }
    while(y!=0){
        b[++cnt2]=y%2;
        y/=2;
    }
    for(int i=max(cnt1,cnt2);i>=1;i--){
        c[i]=a[i]+b[i];
        cout<<c[i];
    }
    
    return 0;
}