//
// Created by marve on 2021/4/27.
//
//
// Created by marve on 2021/4/27.
//
#include<stdio.h>
#define MaxSize 20

typedef struct{
    int data[MaxSize];
    int length;
}SeqList;

void InitList(SeqList& L){
    for(int i=0;i<MaxSize;i++){
        L.data[i]=0;
    }
    L.length=MaxSize;
}

bool ListDelete(SeqList& L,int i, int& e){
    if(i<1||i>L.length){//判断i的范围是否有效
        return false;
    }
    e = L.data[i-1];    //将被删除的元素赋值给e
    for(int j=i;i<L.length;j++){    //将第i个位置后的元素前移
        L.data[j-1] = L.data[j];
    }
    L.length--;     //线性表长度减1
    return true;
}

bool ListInsert(SeqList& L,int i, int e){
    if(i<0||i>L.length+1){
        return false;
    }
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
int GetElem(SeqList L,int i){

}

int main(){
    SeqList L;//声明一个顺序表
    InitList(L);//初始化顺序表

    int e=-1;//用变量e把删除的元素带回来
    printf("good for you\n");
    if(ListDelete(L,3,e)){
        printf("成功删除第三个元素，第三个元素值为%d\n",e);
    }
    else{
        printf("位序i不合法，删除失败\n");
    }

    return 0;
}


