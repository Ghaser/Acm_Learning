#include<bits/stdc++.h>
using namespace std;
//odd 单数 even 双数 consecutive 连续的
//2 奇数 3 either 4 偶数 5
int main(){
    int n;
    cin>>n;
    if(n%2==1){
        cout<<"Either"<<endl;
    }else if(n%2==0&&(n/2)%2==1){
        cout<<"Odd"<<endl;
    }else if(n%2==0&&(n/2)%2==0){
        cout<<"Even"<<endl;
    }


    
    return 0;
}