#include<iostream>
#include<string>
using namespace std;
    int len;
int nexte[1000010];
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
    int mark=1;
    string s;
    while(scanf("%d",&len)&&len){
        cin>>s;
        Getnext(s);
        printf("Test case #%d\n", mark++);
        for(int i=1;i<=len;i++){
            int klen=i-nexte[i];
            if(i!=klen&&i%klen==0){
                printf("%d %d\n", i, i / klen);
            }
        }
        printf("\n");
    }

    return 0;
}