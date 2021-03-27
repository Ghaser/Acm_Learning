#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//P1.A T C G考虑互补链
//将所有链的起始点都设置为A C
//P2.如何输出？ 
//遍历所有count
//P3.如何初始化trie tree
struct node{
    int count;
    bool judge;
    node *child[5];
    node(){
        count=0;
        judge=false;
        for(int i=1;i<=4;i++){
            child[i]=NULL;
        }
    }

};
node root;
int n,m,answer[20005];
void insert(char s[25]){
    node *r=&root;
    for(int i=0;i<m;i++){
        int intS=s[i];//强制将字符转化为对应ascii码
        if(intS==65)intS=1;
        if(intS==67)intS=2;
        if(intS==71)intS=3;
        if(intS==84)intS=4;//减少占用内存
        //cout<<intS<<endl;
        if(r->child[intS]==NULL)r->child[intS]=new node();
        r=r->child[intS];
    }
    r->count++;
    r->judge=true;//judge用来判断是否结尾点

}
void work(node *r){
    if(r->judge){
            answer[r->count]++;
        }
    for(int i=1;i<=4;i++){
        if(r->child[i]!=NULL){
            work(r->child[i]);
        }
        //free(r->child[i]);
    }
}

int main(){
    char str[25];
    while(1){
        root.judge=NULL;
        for(int i=65;i<=84;i++)root.child[i]=NULL;
        memset(answer,0,sizeof(answer));
        cin>>n>>m;
        if(n==0&&m==0){
            break;
        }
        for(int i=1;i<=n;i++){
            scanf("%s",str);
            if(str[0]!='A'&&str[0]!='C'){
                for(int i=0;i<m;i++){
                    if(str[i]=='T'){
                        str[i]='A';
                        continue;
                    }
                    if(str[i]=='A'){
                        str[i]='T';
                        continue;
                    }
                    if(str[i]=='C'){
                        str[i]='G';
                        continue;
                    }
                    if(str[i]=='G'){
                        str[i]='C';
                        continue;
                    }
                }//将DNA序列统一到相近链开头必是A或C
            }
            insert(str);
        }
        work(&root);
        for(int i=1;i<=n;i++){
            cout<<answer[i]<<endl;
        }
    }
    return 0;
}


/*
    answer[count-1]++;



*/

/*


9 6
AAAAAA
65    
65    
65    
65    
65    
65    
ACACAC
65    
67    
65
67
65
67
GTTTTG
67
65
65
65
65
67
ACACAC
65
67
65
67
65
67
GTTTTG
67
65
65
65
65
67
ACACAC
65
67
65
67
65
67
ACACAC
65
67
65
67
65
67
TCCCCC
65
71
71
71
71
71
TCCCCC
65
71
71
71
71
71



*/