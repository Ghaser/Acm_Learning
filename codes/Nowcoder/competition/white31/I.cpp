#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
    bool flag=true,flag2=true;
    cin>>s;
    int n=s.length();
    
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])flag=false;
    }
    if(flag){
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1])flag2=false;
        }
        if(flag2){
            cout<<'0'<<endl;
            return 0;
        }
        cout<<n-1<<endl;

    }else{
        cout<<n<<endl;
    }



    return 0;
}