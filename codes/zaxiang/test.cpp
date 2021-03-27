#include<bits/stdc++.h>
using namespace std;
int nexte[35];
void Getnext(string t){
    int j=0,k=-1;
    nexte[0]=-1;
    while(t[j]!='\0'){
        if(k==-1||t[j]==t[k]){
            j++;
            k++;
            nexte[j]=k;
        }else k=nexte[k];//向前回溯，
    }
}


int main(){
    string s;
    cin>>s;
    Getnext(s);
    for(int i=0;i<=12;i++){
        cout<<i<<' '<<nexte[i]<<endl;
    }
    


    return 0;
}