#include <stdio.h>
#include <stdlib.h>
#include "Link Stack.h"


int main()
{
    int choose;//表示功能的选择
    int number;//表示入栈的个数
    int value;//表示进栈的元素
do{
		printf("\n");
		printf("/////////链栈的基本功能///////\n");
		printf("----------1：置空栈-------------\n");
		printf("----------2: 进栈-------------------\n");
		printf("----------3: 退栈------------------\n");
		printf("----------4: 取栈顶元素--------\n");
		printf("----------5: 退出程序-----------\n");
		printf("\n");
		printf("请选择你想要的功能");
		scanf("%d",&choose);
		switch(choose){
				case 1:{
						top=NULL;
						printf("栈已置空");
					}break;
				case 2:{
						printf("请输入要进栈的元素个数是: ");
						scanf("%d",&number);
						printf("请依次输入要进栈的元素");
						for(int i=0;i<number;i++){
                                scanf("%d",&value);
                                top=Push(top,value);
                        }
                        printf("进栈已完成！\n");
                        printf("\n输出栈为:");
                        Print();
                        }break;
                case 3:{
                        printf("\n操作之前的输出栈为:");
                        Print();
                        top=Pop(top);
                        printf("\n操作过后的输出栈为:");
                        Print();
                        }break;
                case 4: {
                        printf("\n输出栈为:");
                        Print();
                        if(top!=NULL)
                            printf("\n栈顶元素是：%d\n",GetStackTop(top));
                        else
                            printf("\n栈是空的，没有元素！");
                        }break;
                case 5:{
                        exit(0);
                        }break;

                }
}while(choose<=5);


    return 0;
}
