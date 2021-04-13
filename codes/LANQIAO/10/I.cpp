#include<bits/stdc++.h>
using namespace std;
//状态压缩DP
//state表示状态，第i位表示第i位糖果是否被选用
int n,m,k,c[105][25];

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>c[i][j];
        }
    }


    return 0;
}