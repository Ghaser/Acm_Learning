//我 是 傻 逼
//发现用STL的优先队列难以实现，尝试手写队列
//坑 所有点的入度均为1
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

int n,in[maxn],out[maxn],to[maxn],maxe=0,cnt=0,cnt1=1,judge[maxn],cnt2=0;
int q[maxn],m[maxn],answer[maxn];
int main(){
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(m,0,sizeof(m));
    memset(judge,0,sizeof(judge));
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        in[b]++;
        out[a]++;
        to[a]=b;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            maxe++;//顺便记录下最大牛奶管道数
            q[++cnt]=i;
            m[i]=1;
            judge[i]=1;
        }
    }
    while(cnt1<=cnt){
        int u=q[cnt1];
        if(out[u]>1){
           m[to[u]]=0;
           ++cnt1;
            continue;
        }
        m[to[u]]+=m[u];
        in[to[u]]--;
        if(!in[to[u]]){
            q[++cnt]=to[u];
        }
        cnt1++;
    }
    for(int i=1;i<=n;i++){
        if(m[i]==maxe&&judge[i]==0)answer[++cnt2]=i;
    }
    for(int i=1;i<=cnt2;i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}