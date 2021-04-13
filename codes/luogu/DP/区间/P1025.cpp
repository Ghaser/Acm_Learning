#include<bits/stdc++.h>
using namespace std;
//区间动态规划，将数n看成n个"1"
//然后将其划分为k个区间
//f[i][x]表示将i划分成x个非空的数的方案数
//i<x时 f[i][x]=0 i=x时 f[i][x]=1
//状态转移方程 f[i][x]=f[i-1][x-1]+f[i-x][x]
//f[i-1][x-1]表示补上一个1
//f[i-x][x]表示在划分中的x区间中所有数总共加上x
int n,k,f[205][10];

int main(){
    cin>>n>>k;
    //----初始化----
    for(int i=1;i<=n;i++){
        f[i][1]=1;//划分为1个区间只有一种情况
        f[i][0]=1;//划分为0个区间也是一种情况
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            if(i>j)f[i][j]=f[i-1][j-1]+f[i-j][j];
            else f[i][j]=f[i-1][j-1];
        }
    }
    cout<<f[n][k]<<endl;

}