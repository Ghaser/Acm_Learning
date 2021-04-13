#include<bits/stdc++.h>
using namespace std;
//寻求数t t使数分为两堆，
//二分答案
int n,w[100005];
bool judge(int t){
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        if(w[i]<t)sum1+=w[i];
        else if(w[i]>t)sum2+=w[i];//这里注意等于部分不会影响二者间的大小关系，故不必讨论
    }
    if(sum1>=sum2)return true;
    else return false;
}


int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    sort(w+1,w+1+n);
    int l=w[1],r=w[n];
    while(l<r){
        
        int mid=(l+r)>>1;
        if(judge(mid))r=mid;//满足情况，寻求最小
        else l=mid+1;
    }

    cout<<l<<endl;
    return 0;
}