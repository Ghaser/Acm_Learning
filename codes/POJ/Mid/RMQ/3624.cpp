#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 50005
//RMQ求出最大值和最小值
int n,m,a[maxn];

int f1[25][maxn],f2[25][maxn];
void rmq_init(){//RMQ算法的预处理
    for(int i=1;i<=n;i++){
        f1[0][i]=a[i];
        f2[0][i]=a[i];
    }
    for(int i=1;i<=25;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            f1[i][j]=min(f1[i-1][j],f1[i-1][j+(1<<(i-1))]);
            f2[i][j]=max(f2[i-1][j],f2[i-1][j+(1<<(i-1))]);
        }
    }
}
int rmq_max(int l,int r){
    int k=0;
    while(1<<(k+1) <r-l+2){//k其实也可以初始化
        k++;
        //cout<<k<<'B'<<endl;
    }
    return max(f2[k][l],f2[k][r-(1<<k)+1]);
}
//f2[k][l]
//f2[k][r-(1<<k)+1]
int rmq_min(int l,int r){
    int k=0;
    while(1<<(k+1) <r-l+2){
        k++;
        //cout<<k<<'A'<<endl;
    }
    return min(f1[k][l],f1[k][r-(1<<k)+1]);
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    rmq_init();
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<(rmq_max(l,r)-rmq_min(l,r))<<endl;
    }


    return 0;
}