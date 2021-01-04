#include <stdio.h>
#include "malloc.h"
typedef struct BNode{
    int data;
    struct BNode *left,*right;
}BNode,*BiTree;

typedef struct SqQueue{
    BiTree data[100];
    int front,rear;
}SqQueue;

void Init(SqQueue &Q){
    Q.rear=Q.front=0;
}

void EnQueue(SqQueue &Q,BiTree T){
    if ((Q.rear+1)%100==Q.front)
        printf("队列为满");
    Q.data[Q.rear+1]=T;
    Q.rear=(Q.rear+1)%100;
}

BiTree DeQueue(SqQueue &Q){
    BiTree p;
    if (Q.rear==Q.front)
        printf("队列为空");
    p=Q.data[Q.front];
    Q.front=(Q.rear+1)%100;
    return p;
}

int isEmpty(SqQueue Q){
    if (Q.rear==Q.front)
        return 1;
    else
        return 0;
}

void create(BiTree &T){
    int x;
    scanf("%d",&x);
    if(x==0)
        T=NULL;
    else{
        T=(BiTree)malloc(sizeof (BNode));
        T->data=x;
        create(T->left);
        create(T->right);
    }
}

void bianli(BiTree T){
    if (T!=NULL){
        printf("%d",T->data);
        bianli(T->left);
        bianli(T->right);
    }
}

void bianli1(BiTree T){
    if(T!=NULL){
        bianli1(T->left);
        printf("%d",T->data);
        bianli1(T->right);
    }
}

void bianli2(BiTree T){
    if(T!=NULL){
        bianli2(T->left);
        bianli2(T->right);
        printf("%d",T->data);
    }
}

void bianli3(BiTree T){
    BiTree p;
    SqQueue Q;
    Init(Q);
    while (!isEmpty(Q)){
        p=DeQueue(Q);
        printf("%d",p->data);
        if(p->left!=NULL)
            EnQueue(Q,p->left);
        if(p->right!=NULL)
            EnQueue(Q,p->right);
    }
}
int main() {
    BiTree T;
    create(T);
    bianli(T);
    printf("\n");
    bianli1(T);
    printf("\n");
    bianli2(T);
    printf("\n");
    bianli3(T);
    printf("\n");
}
