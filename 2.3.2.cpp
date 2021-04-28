//
// Created by marve on 2021/4/28.
//
#include<stdio.h>
#include<malloc.h>

typedef struct LNode{
    int data; //节点中的数据
    struct LNode* next; //指向下一个节点的指针
}LNode,* LinkList;

bool ListInsert(LinkList &L,int i,int e){
    if(i < 1){
        return false;
    }
    LNode *p;
    p = L;//首先让p指向头节点
    int j = 0;//表示现在p指向节点的位序
    while(p->next!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert1(LinkList &L,int e,int i){
    if(i<1){
        return false;
    }
    if(i==1){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next;
        L = s;
        return true;
    }
    LNode *p = L;
    int j = 1;
    while(j<i-1&&p!=NULL){
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s ->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插操作，在p节点后插入元素e
bool InsertNextNode(LNode* p,int e){//指定节点的后插操作
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插操作，在第i个节点后插入元素e(带头节点)
bool ListInsert2(LinkList& L,int i, int e){
    if(i==0){
        return false;
    }
    LNode *p = L;
    int j = 0;
    while(j<i-1&&p!=NULL) {
        p = p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    return InsertNextNode(p,e);
}

//前插操作，在p节点之前插入元素e
bool InsertPriorNode(LNode *p,int e){
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->next = p->next;
    s->data = p->data;
    p->next = s;
    p->data = e;
    return true;
}
//前插操作:在p节点之前插入节点s
bool InsertPriorNode1(LNode* p,LNode* s){
    if(p==NULL||s==NULL){
        return false;
    }
    int temp = p->data;
    p->data = s->data;
    s->next = p->next;
    p->next = s;
    s->data = temp;
    return true;
}

//按位序删除,带头节点
bool ListDelete(LinkList &L,int i,int &e){
    if(i<1){
        return false;
    }
    LNode *p = L;
    int j = 0;
    while(j<i-1&&p!=NULL){
        p = p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    p->next = p->next->next;
    e = p->next->data;
    free(p->next);
    return true;
}

//指定节点的删除，删除指定节点p
bool DeleteNode(LNode *p){
    if(p==NULL){
        return false;
    }
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
    //但是存在bug，当p为最后一个节点是p->next = NULL
    //因此我们只能从头开始寻找p的前驱，时间复杂度为O(n)
}
int main(){

    return 0;
}
