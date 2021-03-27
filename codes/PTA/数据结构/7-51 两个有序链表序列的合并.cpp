#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;
List Merge(List L1,List L2){
    List temp1=L1->Next;
    List temp2=L2->Next;
    List p;
    p=(List)malloc(sizeof(struct Node));
    p->Next=NULL;
    List temp=p;
    while(temp1&&temp2){
        if(temp1->Data<temp2->Data){
            temp->Next=temp1;
            temp1=temp1->Next;
            temp=temp->Next;
        }else{
            temp->Next=temp2;
            temp2=temp2->Next;
            temp=temp->Next;
        }
    }
    while (temp1!=NULL){
        temp->Next=temp1;
        temp1=temp1->Next;
        temp=temp->Next;
        /* code */
    }
    while(temp!=NULL){
        temp->Next=temp2;
        temp2=temp2->Next;
        temp=temp->Next;
    }
    temp->Next=NULL;
    return p;
}

int main(){
    List L1,L2;



    return 0;
}
