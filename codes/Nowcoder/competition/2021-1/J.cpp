#include<bits/stdc++.h>
using namespace std;
#define ll long long
//真 暴力
//每一行黑色个数都为n/2
//暴力 行判断一次，列判断一次，
//暴力如何记录下连续个数？
//DP 搜索
ll n,counte,l1,l2;
string p[25];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        counte=0;
        l1=0;
        l2=0;
        for(int j=0;j<n;j++){
            if(p[i][j]=='W'){
                counte++;
                l1++;
                l2=0;
            }else{
                l2++;
                l1=0;
            }
            if(l1==3||l2==3){
                cout<<"0"<<endl;
                return 0;
            }
        }
        
        if(counte!=n/2){
            cout<<"0"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        counte=0;
        l1=0;
        l2=0;
        for(int j=0;j<n;j++){
            if(p[j][i]=='W'){
                counte++;
                l1++;
                l2=0;
            }else{
                l2++;
                l1=0;
            }
            if(l1==3||l2==3){
                cout<<"0"<<endl;
                return 0;
            }
        }
        if(counte!=n/2){
            cout<<"0"<<endl;
            return 0;
        }
    }
    cout<<"1"<<endl;

    return 0;
}