#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * 链表结点
 */
typedef struct TNode{
    int data;
    struct TNode *next;
    struct TNode *pre;
} TNode, *ptr_TNode;


typedef enum Status
{
    SUCCESS, ERROR
}Status;

ptr_TNode create(int *arr, int n) {
    ptr_TNode head, p, r;
    ptr_TNode pointerNode; // 该变量的
    int i = 0;
    if( n<=0)
    {
        printf("the n is error!");
    }
    //创建头结点，头指针指向头结点
     head = (ptr_TNode)malloc(sizeof(TNode));
    head->data = 0; //存放结点个数（除去头结点）
    head->next = head;
    head->pre = head;    //空的双向链表
    r = head;
    for(i = 0; i < n; i++) {
        p = (TNode *)malloc(sizeof(TNode)); //生成新结点
        p->data = arr[i];
        r->next = p;
        p->next = head;
        p->pre  = r;
        head->pre = p;
        r = p;
        head->data++;//师姐，这是网上找的，但是这一步不太能理解，求解答，谢谢
    }

    return head;
}
//销毁给定的链表
void destroy(ptr_TNode head)
{
    ptr_TNode p,q;
    p = head->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    head->next = NULL;
}


//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print( ptr_TNode head)
{
    int i = 0;
    ptr_TNode p = head; //让p指向第一个元素
    for( i=1; i<=head->data+1; i++)
    {
       printf("%-4d", p->data);

       if( i%5==0)
       {
           printf("\n");
       }
       p = p->next;
    }

}
//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中
Status delete_T(ptr_TNode *head, int index, int *data)
{
    int j;
   if( index < 0 )
   {
       printf("the index is error!");
       return ERROR;
   }

   ptr_TNode p,q;
   p = NULL;

   p = *head;  //p指向头结点
   j = 0;
   while( p && j<index)//找到删除的位置
   {
       p = p->next;
       j++;
   }

   if( p->next == *head)
   {
       printf("不能删除 该结点为头结点");
       return ERROR;
   }

    q = p->next;
    q->next->pre = p;
    p->next = q->next;
    *data = q->data;
    free(q);
    //q=NULL;//查的一些资料有这句，但一些没有，我觉得这句可以不用，加这句是为了什么呀？

   return SUCCESS;
}
//双向链表,在第 index 位后面插入 node 结点
//插入成功返回 SUCCESS，失败返回 ERROR
Status insert_T( ptr_TNode *head, ptr_TNode node, int index)
{
   int j;
   if( index < 0 )
   {
       printf("the index is error!");
       return ERROR;
   }

   ptr_TNode p ,q;

   p = *head;  //p指向头结点
   j = 0;
   //找到插入的位置//
   while( p && j<index)
   {
       p = p->next;
       j++;
   }

   q = p->next;
   p->next = node;
   node->next = q;
   node->pre = p;
   q->pre = node;
   (*head)->data++;
   return SUCCESS;

}

