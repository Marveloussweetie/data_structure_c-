//
// Created by marve on 2021/4/28.
//
#include<stdio.h>
#include<malloc.h>

typedef struct LNode{
    int data; //节点中的数据
    struct LNode* next; //指向下一个节点的指针
}LNode,* LinkList;

bool InitList(LinkList& L){//不带头节点的单链表
    L = NULL;
    return true;
}
bool InitialList(LinkList &L){//带头节点的单链表
    L = (LinkList)malloc(sizeof(LNode));
    if(L==NULL){
        return false;
    }
    L->next = NULL;
    return true;
}
int main(){
    LinkList L;
    InitList(L);

    InitialList(L);

    return 0;
}
