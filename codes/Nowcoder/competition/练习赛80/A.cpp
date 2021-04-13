#include<bits/stdc++.h>
using namespace std;
string str;
int counte;
priority_queue<int> ans;
//可以将一个1变成0来减小全1串的长度
//遍历最长全1串，从中间断开，最长串长度为n/2
int main(){ 
    cin>>str;
    for(int i=0;i<=str.length();i++){
        if(str[i]=='1'){
            counte++;
        }else{
            ans.push(counte);
            counte=0;
        }
    }
    int ans1=ans.top();
    ans.pop();
    int ans2=ans.top();
    ans.pop();
    //cout<<ans1<<endl<<ans2<<endl;
    cout<<max(ans1/2,ans2)<<endl;
    return 0;
}