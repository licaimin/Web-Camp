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

//根据数组生成一条双向链表，成功则返回头节点，失败返回 NULL
ptr_TNode create(int *arr, int n);
//销毁给定的链表
void destroy(ptr_TNode head);
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print( ptr_TNode head);
//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中
Status delete_T(ptr_TNode *head, int index, int *data);
//双向链表,在第 index 位后面插入 node 结点
//插入成功返回 SUCCESS，失败返回 ERROR
Status insert_T( ptr_TNode *head, ptr_TNode node, int index);

*/
int main()
{
    ptr_TNode create(int *arr, int n);
    void print( ptr_TNode head);
    int a[SIZE]={1,2,3,4,5,6,7,8,9,10};
    ptr_TNode head = create(a,10);
    printf("创建链表(第一个数字表示链表的结点数）：\n");
    print(head);

    while(1)
    {
        int choose;
        printf("\n\n请选择你想要的功能\n");
        printf("1:表示插入  2:表示删除  3:表示退出\n");
        scanf("%d",&choose);
        if(choose==1)
        {
            int data1,index;
           printf("请输入你想插入的数据");
           scanf("%d",&data1);
           printf("请输入你想插入的位置（从0开始）");
           scanf("%d",&index);
           if(index>head->data)
           {
               printf("你输入的插入位置有误\n");
               print(head);
           }
           else{
                 ptr_TNode inse =(ptr_TNode)malloc(sizeof(TNode));//生成新结点
                 inse->next=NULL;
                 inse->data=data1;

                 if((insert_T(&head,inse,index))==0){//注意是取址符号，取头结点的地址，不过诗琪师姐，我还是不太懂，我是试出来才知道的

                        print(head);
                   }
           }


        }
        if(choose==2)
        {
                        int num;
            printf("\n");
            printf("请输入你要删除第几位元素（从0开始）");
            scanf("%d",&num);
                int *deletedata;
            if(num>head->data){
                printf("你输入的位置有误\n");
                print(head);
                printf("\n");
            }
            else{
                    if((delete_T(&head,num,&deletedata))==0)//在函数那里data是指针的指针，所以要加取址
               {
                   head->data--;
                   print(head);
                   printf("\n");
                   printf("被删除的元素是%d",deletedata);

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
        printf("\n请输入1~3的数字");
    }
    }

    return 0;
}






