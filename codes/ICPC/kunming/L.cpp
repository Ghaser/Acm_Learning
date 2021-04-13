//逆序对
//寻找出所有逆序对从而进行建图
//图的着色问题
//不断求解所给排序的最长上升子序列
//每一种轮最长上升子序列一种涂色(由于是正序，之间一定没有连边)
//Dilworth定理 求最长下降子序列的长度
//但是涂色还是要求出所有的最长上升子序列
#include<bits/stdc++.h>
using namespace std;
int n,t,a[1000005],c[1000005],low[1000005],up[1000005],ans,len1,as[1000005],len2;
int num1[1000005],num2[1000005];
int main(){
    cin>>t;
    while(t--){
        memset(up,0,sizeof(up));
        memset(low,0,sizeof(low));
        memset(c,0,sizeof(c));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        low[1]=a[1];
        up[1]=a[1];
        ans=1;
        for(int i=2;i<=n;i++){
            int p1=lower_bound(up+1,up+1+ans,a[i])-up;
            p1<=ans?up[p1]=a[i]:up[++ans]=a[i];
        }//先求出最长上升子序列的最小划分数
        ans--;
        for(int k=1;k<=ans;k++){
            len1=1;
            len2=1;
            for(int i=1;i<=n;i++){
                if(a[i]!=0){
                    low[1]=a[i];
                    as[1]=a[i];//初始化为第一个未被使用的排序中顶
                    break;
                }
            }
            for(int i=num1[1];i<=n;i++){
            if(as[len2]<a[i]){
                as[++len2]=a[i];
                num2[len2]=i;
            }
            if(low[len1]<a[i]){
                low[++len1]=a[i];
                num1[len1]=i;
                }
            else{
                int p1=lower_bound(low+num1[1],low+1+len1,a[i])-low;
                low[p1]=a[i];
                num1[p1]=i;
            }
            }
            if(len2<len1){
                len2=len1;
                for(int i=1;i<=len1;i++){
                    as[i]=low[i];
                    num2[i]=num1[i];
                }
            }
            for(int i=1;i<=len2;i++){
                //cout<<num2[i]<<'A'<<' ';
                //cout<<endl;
                c[num2[i]]=k;
                a[num2[i]]=0;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            cout<<c[i]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}

//样例分析
//对于任意一个数a，在其中后且比其小者一定与其右边
//1 6 5 4 7 8 2 3
//4   
//1 4 7 8
//
//
//
//