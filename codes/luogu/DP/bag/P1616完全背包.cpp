#include<bits/stdc++.h>
using namespace std;
long long a[10005],b[10005],f[10000005],ans=0;
int main(){
    long long t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    for(long long  i=1;i<=m;i++){
        for(long long j=a[i];j<=t;++j){
            f[j]=max(f[j-a[i]]+b[i],f[j]);
            ans=max(ans,f[j]);
        }
    }
    cout<<ans<<endl;


    return 0;
}