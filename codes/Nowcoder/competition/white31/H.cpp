#include<bits/stdc++.h>
using namespace std;
//分别检索最前面和最后面两个字符串
int t,n,a1[27],a2[27],judge=1;
string s[105];

int main(){
    cin>>t;
    while(t--){
        judge=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
         for(int i=1;i<=n/2;i++){
            for(int j=1;j<=s[i].length();j++){
                int p=s[i][j]-'a'+1;
                a1[p]=1;
            }
            for(int j=1;j<=s[n-i+1].length();j++){
                int p=s[n-i+1][j]-'a'+1;
                a2[p]=1;
            }
            for(int j=1;j<=26;j++){
                if(a1[j]&&a2[j]){
                    break;
                }
                if(j==26){
                    judge=0;
                }
            }
        }
        if(judge){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

    }
   


    return 0;
}