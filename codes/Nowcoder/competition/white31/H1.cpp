#include<bits/stdc++.h>
using namespace std;
//分别检索最前面和最后面两个字符串
int t,n,a1[27],a2[27],judge=1;
string s[105];

int main(){
    cin>>t;
    while(t){
        t--;
        judge=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
         for(int i=1;i<=n/2;i++){
             memset(a1,0,sizeof(a1));
             memset(a2,0,sizeof(a2));
             int l1=s[i].length(),l2=s[n-i+1].length();
            for(int j=1;j<=l1;j++){
                int p=s[i][j]-'a'+1;
                a1[p]=1;
            }
            for(int j=1;j<=l2;j++){
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