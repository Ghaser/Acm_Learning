#include<bits/stdc++.h>
using namespace std;
//类杨辉三角
//从下往上推进
//字典序最小，左边尽可能小于右边
//广度优先搜索
//第一行的数是固定的，从1到n
//dfs对第一行进行枚举,运用公式来与sum比较
//打表，yyds！
//大可不必
//组合数
//int c[13][13]={{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,8,8,5,1},{1,6,10,12,10,6,1},}
int n,sum,a[20],visit[20],c[20];
//visit数组用来保障每个数只被枚举一次
void dfs(int x,int sum1){
//x为已经枚举数的个数,sum1枚举过数的理论和，用以剪枝，
    if(sum1>sum){
        return;//剪枝一
    }
    if(x==n){
        if(sum1==sum){
         for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        exit(0);
         }
    }
   //终点情况
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            visit[i]=1;
            a[x+1]=i;
            dfs(x+1,sum1+i*c[x+1]);
            visit[i]=0;//回溯   
        }
    }
}
int main(){
    cin>>n>>sum;
    memset(visit,0,sizeof(visit));
    c[1]=c[n]=1;
    for(int i=2;i<=n/2+1;i++){
        c[i]=(n-i+1)*c[i-1]/(i-1);
        c[n-i+1]=(n-i+1)*c[i-1]/(i-1);
    }
    dfs(0,0);
    return 0;
}

//sum=(a[1]+a[n])*0*n+(a[2]+a[n-1])*(n-1)+(a[3]+a[n-2])*2*(n-2)
//  1 2 3 4 5
//   3 5 7 9
//    8 12 16
//    20 28
//      48
//6+6*4+

//    3   1   2   4  6
//      4   3   6  10
//        7   9  16
//          16  25
//            41
//9+(1+2+4)*4=37
//9+5*4+2*6
