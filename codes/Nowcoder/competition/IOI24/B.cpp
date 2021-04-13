#include<bits/stdc++.h>
using namespace std;
//暴力枚举 怕是会死人
//#define maxn 10000000000000000000000000
inline __int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
__int128 trans(string s){
    __int128 n=0;
    __int128 m=s.length();
    __int128 i=0;
    while(i!=m){ 
        __int128 c=s[i]-'0';
        n=n*10+c;
        i++;
    }
    return n;
}


int main(){
    ios::sync_with_stdio(0);
    __int128 l=read();
    __int128 r=read();
    __int128 ans=0;
    string a;
    cin>>a;
    for(__int128 i=0;i<a.length();i++){
        for(__int128 j=0;j<a.length();j++){
            string s=a.substr(i,j-i);
            __int128 num;
            num=trans(s);
            if(num>r)break;
            else if(num>=l)ans++;
        }
    }
    print(ans);
    return 0;
}