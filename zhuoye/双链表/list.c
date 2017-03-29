#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * ������
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
    ptr_TNode pointerNode; // �ñ�����
    int i = 0;
    if( n<=0)
    {
        printf("the n is error!");
    }
    //����ͷ��㣬ͷָ��ָ��ͷ���
     head = (ptr_TNode)malloc(sizeof(TNode));
    head->data = 0; //��Ž���������ȥͷ��㣩
    head->next = head;
    head->pre = head;    //�յ�˫������
    r = head;
    for(i = 0; i < n; i++) {
        p = (TNode *)malloc(sizeof(TNode)); //�����½��
        p->data = arr[i];
        r->next = p;
        p->next = head;
        p->pre  = r;
        head->pre = p;
        r = p;
        head->data++;//ʦ�㣬���������ҵģ�������һ����̫����⣬����лл
    }

    return head;
}
//���ٸ���������
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


//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
void print( ptr_TNode head)
{
    int i = 0;
    ptr_TNode p = head; //��pָ���һ��Ԫ��
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
//˫������,ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data����
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

   p = *head;  //pָ��ͷ���
   j = 0;
   while( p && j<index)//�ҵ�ɾ����λ��
   {
       p = p->next;
       j++;
   }

   if( p->next == *head)
   {
       printf("����ɾ�� �ý��Ϊͷ���");
       return ERROR;
   }

    q = p->next;
    q->next->pre = p;
    p->next = q->next;
    *data = q->data;
    free(q);
    //q=NULL;//���һЩ��������䣬��һЩû�У��Ҿ��������Բ��ã��������Ϊ��ʲôѽ��

   return SUCCESS;
}
//˫������,�ڵ� index λ������� node ���
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR
Status insert_T( ptr_TNode *head, ptr_TNode node, int index)
{
   int j;
   if( index < 0 )
   {
       printf("the index is error!");
       return ERROR;
   }

   ptr_TNode p ,q;

   p = *head;  //pָ��ͷ���
   j = 0;
   //�ҵ������λ��//
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

