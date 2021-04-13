//时间估计 O（n）
//适用于n>k的情况(n<k时执行插入)
//插入的数和a[k]比较大小
//大于a[k]忽略
//小于a[k]与a[k-1]比较
//若大于a[k-1] 更新a[k]
//若小于a[k-1] 则对数组进行更新
#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[200005];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(m--){
        int t,t1;
        cin>>t;
        if(n>=k){
        if(t==2){
            cout<<a[k]<<endl;
        }else if(t==1){
            cin>>t1;
            if(t1>a[k]){
                //empty
            }else if(t1<a[k-1]){
                int j=k;
                while(t1<a[j]){
                    a[j]=a[j-1];
                    j--;                                      
                }
                j++;
                a[j]=t1;
            }else if(t1>=a[k-1]&&t1<=a[k]){
                a[k]=t1;
            }
        }
        }else{
            if(t==1){
            cin>>t1;
            int j=n;
            while(t1<a[j]){
                a[j+1]=a[j];
                j--;                                      
            }
            j++;
            a[j]=t1;
            }else if(t==2){
                cout<<"-1"<<endl;
            }
        }
    }
    
    return 0;
}