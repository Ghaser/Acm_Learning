//我 是 傻 逼
//发现用STL的优先队列难以实现，尝试手写队列
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
//1 2 3 4 5 6 7 8 9
/*暴力枚举
先找出入度为0的点，然后枚举其所有单向联通的顶点
过于暴力
*/
/*考虑拓扑

*/
struct node{
    int u,p;
    bool operator<(const node& rhs)const{
        return p>rhs.p;
    }
};//优先队列，我们先pop出管道数小的点，才能为后面的点做准备
int n,in[maxn],out[maxn],m[maxn],maxe=0;
priority_queue<node> q;
vector<int> edge[maxn];
int main(){
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(m,0,sizeof(m));
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        in[b]++;
        out[a]++;
        edge[a].push_back(b);
    }
    for(int i=1;i<=0;i++){
        if(in[i]=0){
            maxe++;//顺便记录下最大牛奶管道数
            q.push((node){i,0});
        }
    }
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int a=x.u,b=x.p;
        for(int i=0;i<edge[a].size();i++){
            int y=edge[a][i];
            
        }
    }

    
    return 0;
}