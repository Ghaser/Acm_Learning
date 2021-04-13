#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200005
//无向图
//最小生成树 白边的赋值原本就比黑边大，故直接求原图的最小生成树即可
//prim or kruskal？
//稀疏图 使用kruskal
//白数个数即为最小生成树的值
//记得考虑特殊情况：无法生成最小生成树
ll fa[maxn],n,m,ans=0,eu,ev,cnt,judge[maxn];
struct Edge{
    int u,v,w;
}edge[maxn];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
ll find(ll x){
    if(fa[x]==0){
        return x;
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
void kruskal(){
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;i++){
        eu=find(edge[i].u);
        ev=find(edge[i].v);
        if(eu==ev){
        continue;
    }
        fa[ev]=eu;
        ans+=edge[i].w;
    }
    

}
int main(){
    memset(judge,0,sizeof(judge));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        judge[edge[i].u]=1;
        judge[edge[i].v]=1;
    }
    for(int i=1;i<=n;i++){
        if(!judge[i]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    kruskal();
    cout<<ans<<endl;
    return 0;
}