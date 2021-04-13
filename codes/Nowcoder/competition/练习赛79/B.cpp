//找到a，b的最小公因数
//然后除上这个数，再将a，b都化为非5，3的倍数即可
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,r1,r2,gcd,ans=0;;
    cin>>n;
    while(n--){
        r1=0;
        r2=0;
        int a,b;
        cin>>a>>b;
        gcd=__gcd(a,b);
        a/=gcd;
        b/=gcd;
        while(a%5==0){
            r1++;
            a/=5;
            a*=3;
        }
        while(b%5==0){
            r1--;
            b/=5;
            b*=3;
        }
        r1=abs(r1);
        while(a%3==0){
            r2++;
            a/=3;
        }
        while(b%3==0){
            r2--;
            b/=3;
        }
        r2=abs(r2);
        if(a!=b){
            cout<<-1<<endl;
            return 0;
        }
        ans+=r1+r2;
    }
    cout<<ans<<endl;
    return 0;
}