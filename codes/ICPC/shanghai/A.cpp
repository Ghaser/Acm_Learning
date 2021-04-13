#include<bits/stdc++.h>
using namespace std;
//判断fibonacci数列中
//暴力枚举是否可取？
//寻找fibonacci数列中的奇偶规律
//odd odd even odd odd even odd odd even
//odd * odd =odd
//odd * even =even
//even *even =even
//暴力超时
//直接算不就得了
//奇数个数乘上偶数个数
#define ll long long 
int main(){
    ll n,ans=0;
    cin>>n;
    ll num1=n%3;
    ll num2=n/3;
    ll odd=num2*2+num1;
    ll even=num2;
    ans=odd*even+even*(even-1)/2;
    cout<<ans<<endl;

    return 0;
}
