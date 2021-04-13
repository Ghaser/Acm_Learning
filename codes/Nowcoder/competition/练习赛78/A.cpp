#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p,ans;
    cin>>n;
    string w[10005];
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cin>>p;
    while(p--){
        ans=0;
        string a;
        cin>>a;
        for(int i=1;i<=n;i++){
            if(w[i]==a||(w[i][1]==a[0]&&w[i][0]==a[1])){
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}