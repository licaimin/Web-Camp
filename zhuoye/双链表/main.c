#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#include "list.h"
/*
typedef struct TNode
{
    int data;
    struct TNode *next;
    struct TNode *pre;
}TNode,*ptr_TNode;

typedef enum Status
{
SUCCESS, ERROR
}Status;

//������������һ��˫�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL
ptr_TNode create(int *arr, int n);
//���ٸ���������
void destroy(ptr_TNode head);
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
void print( ptr_TNode head);
//˫������,ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data����
Status delete_T(ptr_TNode *head, int index, int *data);
//˫������,�ڵ� index λ������� node ���
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR
Status insert_T( ptr_TNode *head, ptr_TNode node, int index);

*/
int main()
{
    ptr_TNode create(int *arr, int n);
    void print( ptr_TNode head);
    int a[SIZE]={1,2,3,4,5,6,7,8,9,10};
    ptr_TNode head = create(a,10);
    printf("��������(��һ�����ֱ�ʾ����Ľ��������\n");
    print(head);

    while(1)
    {
        int choose;
        printf("\n\n��ѡ������Ҫ�Ĺ���\n");
        printf("1:��ʾ����  2:��ʾɾ��  3:��ʾ�˳�\n");
        scanf("%d",&choose);
        if(choose==1)
        {
            int data1,index;
           printf("������������������");
           scanf("%d",&data1);
           printf("��������������λ�ã���0��ʼ��");
           scanf("%d",&index);
           if(index>head->data)
           {
               printf("������Ĳ���λ������\n");
               print(head);
           }
           else{
                 ptr_TNode inse =(ptr_TNode)malloc(sizeof(TNode));//�����½��
                 inse->next=NULL;
                 inse->data=data1;

                 if((insert_T(&head,inse,index))==0){//ע����ȡַ���ţ�ȡͷ���ĵ�ַ������ʫ��ʦ�㣬�һ��ǲ�̫���������Գ�����֪����

                        print(head);
                   }
           }


        }
        if(choose==2)
        {
                        int num;
            printf("\n");
            printf("��������Ҫɾ���ڼ�λԪ�أ���0��ʼ��");
            scanf("%d",&num);
                int *deletedata;
            if(num>head->data){
                printf("�������λ������\n");
                print(head);
                printf("\n");
            }
            else{
                    if((delete_T(&head,num,&deletedata))==0)//�ں�������data��ָ���ָ�룬����Ҫ��ȡַ
               {
                   head->data--;
                   print(head);
                   printf("\n");
                   printf("��ɾ����Ԫ����%d",deletedata);

               }
            }
         }
    if(choose==3)
    {
        exit(0);
        break;
    }
    else
    {
        printf("\n������1~3������");
    }
    }

    return 0;
}






