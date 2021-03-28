#include<bits/stdc++.h>
using namespace std;
int w[105],v[105];
int f[1005];
int m,n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j>=w[i]){
                f[j]=max(f[j-w[i]]+v[i],f[j]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;


}