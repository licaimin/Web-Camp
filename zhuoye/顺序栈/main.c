#include <stdio.h>
#include <stdlib.h>
#include "Spstack.h"
                             //通常的习惯做法是以top=0表示空栈，鉴于C语言中数组的下标约定从0开始，则当以C作描述语言时，如此设定会带来很大不便；另一方面，由于栈的使用过程中所需最大空间的大小很难估计，因此，一般来说，在初始化设空栈时不应限定栈的最大容量。一个较合理的做法是：先为栈分配一个基本容量，然后再应用过程中，当栈的空间不够使用时再逐段扩大。为此。可设定两个常量：STACK_INIT_SIAE(存储空间初始分配量)和STACKKINCREMENT(存储空间分配增量


int main()
{

     SqStack S;
     int e,choose,data;
     do{
        printf("\n");
        printf("\n");
        printf("\n      主菜单     \n");
        printf("\n   1 建立一个栈  \n");
        printf("\n   2 获取栈顶元素 \n");
        printf("\n   3 插入新的栈顶元素  \n");
        printf("\n   4 删除栈顶元素  \n");
        printf("\n   5 退出程序  \n");
        printf("\n-------------------\n");
        printf("请选择你想要的功能");
        scanf("%d",&choose);
        printf("\n");
        switch(choose){
        case 1:
                {
                    InitStack(&S);
                    build(&S);
                    Print(&S);
                }break;
        case 2:
                {
                    GetTop(&S,e);
                }break;

        case 3:
                {
                    printf("请输入你想要插入的数值");
                    scanf("%d",&data);
                    Push(&S,data);
                    printf("插入新的栈顶元素之后");
                    Print(&S);
                }break;

        case 4:
                {
                    Pop(&S,e);
                    printf("删除栈顶元素之后");
                    Print(&S);
                }break;

        case 5:
                {
                    printf("谢谢使用");
                    exit(0);
                }break;

        }
       } while (choose<=5);

    return 0;

}
