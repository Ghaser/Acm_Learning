#include<bits/stdc++.h>
using namespace std;
//统计所有子串中恰好出现一次的字符个数
//单子串均为1 n个
//双子串为0，2 n-1个 判断前后是否重复
//三子串为0，1，3 n-2个
//可见长子串的f值可以由短子串的f值推出
//考虑动态规划
//dp[i][j]
//i表示子串长度，j表示前一子串的状态
#define ll long long
ll dp[100005],a[100005];//对dp数组进行一维空间优化
map<string,int> m;
int main(){

    int n;
    string str;
    cin>>n;
    cin>>str;
    
    for(int i=0;i<=1;i++){

    }


    return 0;
}

