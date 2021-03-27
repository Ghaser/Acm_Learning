#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//Hash 连加求余法，用链地址发法解决冲突
//打表法快速判断两个雪花是否相同
#define ll long long
#define mod 99991
#define maxn 100010
int a[maxn][7],n;
ll sum;
vector<int>v[maxn];
bool check(int x,int y){
    for(int i=0;i<6;i++){
        //同向
        if(a[x][0]==a[y][i]&&a[x][1]==a[y][(i+1)%6]
		 &&a[x][2]==a[y][(i+2)%6]&&a[x][3]==a[y][(i+3)%6]
		 &&a[x][4]==a[y][(i+4)%6]&&a[x][5]==a[y][(i+5)%6])return 1;
		//反向
        if(a[x][0]==a[y][i]&&a[x][1]==a[y][(i+5)%6]
		 &&a[x][2]==a[y][(i+4)%6]&&a[x][3]==a[y][(i+3)%6]
		 &&a[x][4]==a[y][(i+2)%6]&&a[x][5]==a[y][(i+1)%6])return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<6;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        sum=0;
        for(int j=0;j<6;j++){
            sum+=a[i][j];
        }
        sum%=mod;
        for(int j=0;j<v[sum].size();j++){
            if(check(i,v[sum][j])){
                cout<<"Twin snowflakes found."<<endl;
                return 0;
            }
        }
        v[sum].push_back(i);

    }
    cout<<"No two snowflakes are alike."<<endl;
    return 0;
}