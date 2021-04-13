#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int t,n,a[maxn],low[maxn],num[maxn],ans,as[maxn];
int main(){
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            num[a[i]]=i;
        }
        for(int i=n;i>=1;i--){
            if(!ans||a[i]>low[ans]){
                low[++ans]=a[i];
                as[i]=ans;
            }else{
                int p1=lower_bound(low+1,low+1+n,a[i])-low;
                as[i]=as[num[low[p1]]];
                low[p1]=a[i];
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            cout<<as[i]<<' ';
        }
        cout<<endl;
    }


    return 0;
}