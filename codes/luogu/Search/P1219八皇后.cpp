//BFS广度优先搜索
#include<bits/stdc++.h>
using namespace std;
int n,c[15],d1[30],d2[30],answer[15],num=0;
void dfs(int i){//这个i代表行
    if(i>n){
        num++;
        if(num<=3){
            for(int j=1;j<=n;j++){
                cout<<answer[j]<<' ';
            }
            cout<<endl;
        }
        return;
    }
    for(int j=1;j<=n;j++){//以列为单位进行遍历
        int da=i-j+n,db=i+j-1;//由一个数的行列可确定其唯一的正、反对角线
        if(c[j]==0&&d1[da]==0&&d2[db]==0){
            answer[i]=j;
            c[j]=1;
            d1[da]=1;
            d2[db]=1;
            dfs(i+1);
            c[j]=0;
            d1[da]=0;
            d2[db]=0;//回溯
        }
    
    }
}


int main(){
    cin>>n;
    dfs(1);
    cout<<num<<endl;
    return 0;
}