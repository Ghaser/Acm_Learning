#include<bits/stdc++.h>
using namespace std;
//恰有k个数 其值与位置的最大公约数为1
// 
//重要结论：gcd(i+1,i)=gcd(i,i+1)=1;
//故我们是前k-1个数满足gcd(i,i+1)
//第k个数对应gcd(k,1)
//其后的数等于本身即可
#define ll long long
ll n,k,a[1000005];
int main(){
    cin>>n>>k;
    if(k<=0||k>n){
        cout<<"-1"<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        if(i<k){
            a[i]=i+1;
        }else if(i==k){
            a[i]=1;
        }else{
            a[i]=i;
        }
    }
    for(int i=1;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<a[n]<<endl;


    return 0;
}