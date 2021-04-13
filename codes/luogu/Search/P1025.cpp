#include<bits/stdc++.h>
using namespace std;
//考虑dfs
//怎么使用深度优先
//搜索使用升序搜索
//
int n,k,ans=0;
void dfs(int x,int sum,int prev){
   if(x==k){
       if(sum==n){
        ans++;
       }
       return;
   }
    for(int i=prev;sum+i*(k-x)<=n;i++)
        dfs(x+1,sum+i,i);
}

int main(){
    cin>>n>>k;
    dfs(0,0,1);
    cout<<ans<<endl;
    return 0;
}