#include<iostream>
#include<cstring>

using namespace std;
//这和tire tree有什么关系？？？
//输入要怎么写？
//使用getchar一一读入(X)
//直接使用gets(能够读入空格但不读入换行符)
int num=0;
class TrieNode{
    public:
        bool isword_;
        int count;
        char name[31];
        TrieNode* child[128];
        TrieNode(){
            count=0;
            isword_=false;
            for(int i=0;i<128;i++){
                child[i]=NULL;
            }
        }

        inline void resetData(){
            count=0;
            isword_=false;
        }
        inline void reset(){
            resetData();
            for(int i=0;i<128;i++){
                child[i]=NULL;
            }
        }
};
TrieNode root;

void insert(char s[31]){
    TrieNode *r=&root;
    int length=strlen(s);
    for(int i=0;i<length;i++){
        int intS=s[i];
        if(r->child[intS]==NULL)r->child[intS]=new TrieNode();
        r=r->child[intS];
    }
    strcpy(r->name,s);
    r->count++;
    r->isword_=true;
}

void print(TrieNode *root){
    if(root->isword_)printf("%s %.4f\n", root->name,root->count*100.0/num);
    for(int i=0;i<128;i++){
        if(root->child[i]!=NULL)print(root->child[i]);
    }
}

int main(){
    char s[31];
    while(gets(s))insert(s),num++;
    print(&root);
    return 0;
}