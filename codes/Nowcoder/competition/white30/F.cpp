//少的一堆石子被直接拿走
//非环形排列石子
//石子数目多的堆可以留着刷分
//考虑贪心
//1.不断拿走数目最少的石子
//2.从数目最多的石子旁边不断拿走石子
//比较:
//显然第二种情况更大
//故本题水题
#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

ll n,s[200005],maxn=0,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        maxn=max(maxn,s[i]);
        ans+=s[i];
    }
    ans+=(n-2)*maxn;
    cout<<ans<<endl;
    return 0;
}

// 2 5 3 5 1 6
// 2 5 3 5   13
//   5 3 5  21
//   5  5   31
