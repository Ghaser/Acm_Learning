
#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int n,m,k;
int s[105];//代表第i包糖果
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        int ss=0;
        int t;
        for(int j=0;j<k;j++)
        {
            scanf("%d",&t);
            ss|=(1<<(t-1));     //将ss二进制状态下第t位设置为1，表示第t种糖果存在。
        }       //在for循环结束后，恰好为一包糖果所含的糖果状态
        s[i]=ss;        //s数组用以存储状态
        dp[ss]=1;       //dp函数的内容值表示选用糖果包的数量
    }
 
    for(int i=0;i<n;i++)    //i遍历不同的糖果包数
    {
        for(int j=0;j<(1<<m);j++)   //j遍历状态
        {
            if(dp[j]==-1)continue;  //以糖果包状态为起始，非糖果包状态直接排除
            if(dp[j|s[i]]==-1)dp[j|s[i]]=dp[j]+dp[s[i]];    //当前状态与新糖果包合并的状态未出现过,直接求和(可写为dp[j]+1)
            else dp[j|s[i]]=min(dp[j|s[i]],dp[j]+dp[s[i]]);     //当前状态与新糖果包合并后的状态出现过，选取达到该状态更小的路径
        }
    }
    printf("%d\n",dp[(1<<m)-1]);
    return 0;
}