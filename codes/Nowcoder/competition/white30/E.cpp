#include<bits/stdc++.h>
using namespace std;
//高精思想

int main(){
    string a,b;
    cin>>a>>b;
    if(a.length()<b.length())swap(a,b);
    int x=a.length(),y=b.length();
    string c=a;
    for(int i=0,j=y-x;i<x;i++,j++){
        if(j>=0){
            c[i]=(a[i]-'0'+b[j]-'0')%10+'0';
        }
    }
    bool flag=false;
    for(int i=0;i<x;i++){
        if(c[i]!='0'||flag){
            cout<<c[i];
            flag=true;
        }
    }
    if(!flag)cout<<0<<endl;
    return 0;

}