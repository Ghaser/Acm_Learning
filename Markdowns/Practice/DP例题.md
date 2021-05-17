# 状态压缩动态规划

## luogu - P3092 Corn Fields G

```c++
#include<bits/stdc++.h>
//常见状态压缩动态规划类型题，摆放问题
using namespace std;
#define mod 100000000
int n,m,cnt;
int amap[15],dp[100000][20],state[600];
//dp[state][i]//表示在状态为state时，到达第i行符合条件的放牛方案数
//dp[state][i]=Σ dp[pre][i-1] pre成为这一行的前一行状态
void init(){
    cnt=0;
    for(int i=0;i< 1<<n;i++){
        if(!(i&i<<1))state[++cnt]=i;//先在0-maxstate中找到合法状态并储存
    }
}
//初始化过程中的合法状态无关肥沃与否，计算出的为任一行可能的排列状态

int main(){
    ios::sync_with_stdio(false);
    cin>>m>>n;
    init();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(!x)amap[i]=amap[i]|(1<<(n-j));//amap中为2进制数，用来表示土地是否可以种草,注意里面的1，0表示值是相反的
        }  
    }
    for(int i=1;i<=cnt;i++){
        if(state[i]&amap[1])continue;
        dp[i][1]=1;//该状态可以，出现一种方案数
    }
    for(int i=2;i<=m;i++){//接下来从第二行开始
        for(int j=1;j<=cnt;j++){//对上一行进行判定
            if(state[j]&amap[i-1])continue;//上一行种草的田地并非全部肥沃
            for(int k=1;k<=cnt;k++){//对改行进行分配
                if(state[k]&amap[i])continue;//如果种在不能种的地方
                if(state[k]&state[j])continue;//如果种在与上一行相邻的位置
                dp[k][i]+=dp[j][i-1];//开始求和dp
                dp[k][i]%=mod;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=cnt;i++){
        ans=(ans+dp[i][m])%mod;
    }
    cout<<ans;



    return 0;
}
```

## luogu P3092 No Change G

状压+二分 

```c++
#include<bits/stdc++.h>
using namespace std;
//状压+二分
//dp[state] state表示硬币使用状态 使用为1
//函数值表示用该状态下可以买到第几个物品
//f[state]表示state状态下的花费
//利用前缀和方便计算中间某段物体的总价格
int n,k;
int coins[20],items[100005],money=0,sum[100005],ans=5123456789;
//注意我们要将
int dp[1<<17],f[1<<17];
int binary(int x,int a){
    //x为硬币的价值,a为硬币的
    int l=a,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(sum[mid]-sum[a-1]==x)return mid;//恰好花完 不会浪费
        if(sum[mid]-sum[a-1]<x)l=mid+1;//钱还有就多买点
        else{
            r=mid-1;//钱不够就少买点
        }
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>k>>n;
    for(int i=1;i<=k;i++){
        cin>>coins[i];//读入硬币的面额
        money+=coins[i];
    }
    for(int i=1;i<=n;i++){
        cin>>items[i];//读入物品的价钱
        sum[i]=sum[i-1]+items[i];//前缀和
    }
    for(int i=1;i<(1<<k);i++){//第一重循环枚举硬币使用状态
        for(int j=0;j<k;j++){//第二重循环枚举硬币编号
            if(i&(1<<j)){//如果第j+1个硬币在当前状态是否被使用
                //我们在使用的状态下方便进行下面dp[i]以及f[i]的更新
                int x=(i^(1<<j)),sum1;
                //x为上一个状态 
                //实际作用就是将第j+1个硬币回归未使用的状态
                //即通过异或操作将状态i的第j位变为0
                sum1=binary(coins[j+1],dp[x]+1);
                if(sum1>dp[i]){
                    dp[i]=sum1;
                    f[i]=f[x]+coins[j+1];
                }
                if(dp[i]==n){
                    ans=min(f[i],ans);
                }
            }
        }
    }
    if(ans>money){
        cout<<"-1"<<endl;
    }else{
        cout<<money-ans<<endl;
    }

    return 0;
}
```

# 杂项

## Nowcoder—The Digits String

题意：求长度为n且总和为4的倍数的数字串个数

```c++
//DP？
//推 dp[n]
//考察dp[n]与dp[n-1]的关系
//设dp[n-1]%4==0 T0个 dp[n-1]%4==1 T1个 dp[n-1]%4==2 T2个  dp[n-3]%4==1 T3个 
//而对于长度为1的字符串s s%4==0 3个 s%4==1 3个 s%4==2 2个 s%4==3 2个
//采用快速幂进行加速
//使用打表模拟计算过程
#include<bits/stdc++.h>
using namespace std;
#define mod 2019
#define ll long long
ll n;
void mul(ll a[],ll b[]){
    ll t[4];
    t[0]=a[0]*b[0]+a[1]*b[3]+a[2]*b[2]+a[3]*b[1];
    t[1]=a[0]*b[1]+a[1]*b[0]+a[2]*b[3]+a[3]*b[2];
    t[2]=a[0]*b[2]+a[1]*b[1]+a[2]*b[0]+a[3]*b[3];
    t[3]=a[0]*b[3]+a[1]*b[2]+a[2]*b[1]+a[3]*b[0];
    for(int i=0;i<4;i++){
        a[i]=t[i]%mod;
    }
}
ll quick_work(ll x){
    ll a[4] = {3,3,2,2};
    ll b[4] = {3,3,2,2};//重新初始化
    while(x){
        if(x&1)mul(a,b);//奇数情况
        mul(b,b);//偶数情况
        x>>=1;//x/=2
    }
    return a[0];
}
int main(){
    while(~scanf("%lld",&n)){
        ll ans=quick_work(n-1);
        cout<<(ans%mod)<<endl;
    }
    
    
    return 0;
}
```

