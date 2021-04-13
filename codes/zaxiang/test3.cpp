#include<bits/stdc++.h>
using namespace std;

int main(){
    int *e1,e2,e3;
    e1=&e3;
    *e1=5;
    e2=*e1;
    cout<<e2<<endl;

    return 0;
}