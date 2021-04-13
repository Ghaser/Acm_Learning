#include <cstdio>
#include <iostream>
#include<bits/stdc++.h>
const int max_n = 31;
typedef long long ll;
ll f[max_n],dp[max_n][max_n];
// 一共有n个物体，要求一共选n个，求选取的总种类数
using namespace std;
int main() {
    int n;
    memset(dp,0,sizeof(dp));
    cin >> n;
    f[0] = 1;
    //将5个分成三个等价于将2分成1个和两个的情况总数
    //将5个分成两个等价于将3分成1个和两个的情况总数之和
    //故将 j分为i个等价于数j-i的分配总数 
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            /**********update f[j] ***********/
            f[j]+=f[j-i];
    
    for(int i=1;i<=n;i++){
        dp[i][1]=1;//划分为1个区间只有一种情况
        dp[i][0]=1;//划分为0个区间也是一种情况
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(i>j)dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
            else dp[i][j]=dp[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[n][i];
    }
    cout << f[n] << ' '<<ans<< endl;
    return 0;
}