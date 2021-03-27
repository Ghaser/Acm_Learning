#include<iostream>
#include<cstring>
using namespace std;
int n,k;
int line[505][505],used[505],node[505],ans=0;

bool find(int x){
    for(int i=1;i<=n;i++){
        if(line[x][i]==1&&used[i]==0){
            used[i]=1;
            if(node[i]==0||find(node[i])){
                node[i]=x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        line[a][b]=1;
    }
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        if(find(i))ans+=1;
    }
    cout<<ans;
    return 0;
}