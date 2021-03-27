#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500005
//树状数组应用场景二，成段更新，单点求值
//如何建树？KEY
//运用数组A前后两项之差构造二叉树
//差分思想与树状数组的完美结合
ll n,c[maxn],m;
ll lowbit(ll x){return x&(-x);}


void add(ll i,ll v){
    while(i<=n){
        c[i]+=v;
        i+=lowbit(i);
    }
}
ll sum(ll i){
    ll s=0;
    while(i){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}


int main(){
    ll temp1,temp2=0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>temp1;
        add(i,temp1-temp2);//建树
        temp2=temp1;
    }
    for(int i=1;i<=m;i++){
        int a,x,y,z;
        cin>>a;
        if(a==1){
            cin>>x>>y>>z;
            add(x,z);
            add(y+1,-z);
        }else if(a==2){
            cin>>x;
            cout<<sum(x)<<endl;
        }
    }


    return 0;
}

//A 1 2 3  4 5  6 7  8
//A* 1 1 1 1 1 1 1 1
//C 1 3 3 10 5 11 7 36
//C* 1 2 1 4 1 2 1 8
//c[1]+=1=1 c[2]+=1 c[4]+=1 c[8]+=1
//c[2]+=2 c[4]+=2 c[8]+=2
//c[3]+=3 c[4]+=3 c[8]+=3
//c[4]+=4 c[8]+=4
//c[5]+=5 c[6]+=5 c[8]+=5
//