#include<bits/stdc++.h>
using namespace std;
#define ll long long
//快速幂？写完发现好像没用。。
ll exp(ll a,ll b){
    ll tmp=1;
    while(b){
        if(b&1)tmp=tmp*a;
        a=a*a;
        b=b/2;
    }
    return tmp;
}


int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        ll x,y,c=0;
        cin>>x>>y;
        if(x==1||x==0||y==0){
            cout<<"-1"<<endl;
        }else if(x==y){
            cout<<"1"<<endl;
        }else if(x>y){
            cout<<"0"<<endl;
        }else{
            while(y){
                y/=x;
                c++;
            }
            cout<<c-1<<endl;
        }
            
        
    }
    
    
    return 0;
}