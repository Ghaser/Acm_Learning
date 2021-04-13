#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 1000005
int n,k,temp;
int a[maxn],q[maxn],p[maxn];
//queue的致命缺点，不能遍历！！！！
//只能由两个数组来实现了
void miner(){
    int s=1,e=0;//start end
    for(int i=1;i<=n;i++){
        while(s<=e&&q[e]>=a[i]){
            e--;//出现更小的元素的话直接对尾元素的编号实现--，从而在赋值操作中完成覆盖
                //等价于pop操作
        }
        q[++e]=a[i];
        p[e]=i;
        while(p[s]<=i-k)
            s++;//对首元素进行pop
        if(i>=k)cout<<q[s]<<' ';
    }
    cout<<endl;
}
void maxer(){
    int s=1,e=0;//start end
    for(int i=1;i<=n;i++){
        while(s<=e&&q[e]<=a[i]){
            e--;
        }
        q[++e]=a[i];
        p[e]=i;
        while(p[s]<=i-k)
            s++;
        if(i>=k)cout<<q[s]<<' ';
    }
    cout<<endl;
}
int main(){
    std::cin>>n>>k;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    miner();
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));
    maxer();

    return 0;
}