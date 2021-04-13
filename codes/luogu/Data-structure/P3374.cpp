#include<iostream>
using namespace std;

int n,m,tree[500005];
//建树操作：通过树状数组的add操作实现
int lowbit(int x){
    return x&(-x);
}

void add(int i,int v){
    while(i<=n){
        tree[i]+=v;
        i+=lowbit(i);
    }

}

int sum(int i){
    int s=0;
    while(i>=1){
        s+=tree[i];
        i-=lowbit(i);
    }
    return s;
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        add(i,a);
    }//建树
    for(int i=1;i<=m;i++){
        int a,b,c,ans;
        cin>>a>>b>>c;
        if(a==1){
            add(b,c);
        }else if(a==2){
            ans=sum(c)-sum(b-1);
            cout<<ans<<endl;
        }
    }


    return 0;
}