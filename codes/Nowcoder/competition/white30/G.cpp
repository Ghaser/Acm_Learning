//水题 贪心+快排
#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int n,m,a[maxn],b[maxn],ans=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    //把a，b都sort的话影响不大
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    for(int i=1,j=1;j<=m;){
        if(a[i]>b[j]){
            ans++;
            i++;
            j++;
        }else{
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

//7 6 4 3 2
//6 4 4 3 2