#include <stdio.h>
#include <stdlib.h>
#include "Link Stack.h"


int main()
{
    int choose;//��ʾ���ܵ�ѡ��
    int number;//��ʾ��ջ�ĸ���
    int value;//��ʾ��ջ��Ԫ��
do{
		printf("\n");
		printf("/////////��ջ�Ļ�������///////\n");
		printf("----------1���ÿ�ջ-------------\n");
		printf("----------2: ��ջ-------------------\n");
		printf("----------3: ��ջ------------------\n");
		printf("----------4: ȡջ��Ԫ��--------\n");
		printf("----------5: �˳�����-----------\n");
		printf("\n");
		printf("��ѡ������Ҫ�Ĺ���");
		scanf("%d",&choose);
		switch(choose){
				case 1:{
						top=NULL;
						printf("ջ���ÿ�");
					}break;
				case 2:{
						printf("������Ҫ��ջ��Ԫ�ظ�����: ");
						scanf("%d",&number);
						printf("����������Ҫ��ջ��Ԫ��");
						for(int i=0;i<number;i++){
                                scanf("%d",&value);
                                top=Push(top,value);
                        }
                        printf("��ջ����ɣ�\n");
                        printf("\n���ջΪ:");
                        Print();
                        }break;
                case 3:{
                        printf("\n����֮ǰ�����ջΪ:");
                        Print();
                        top=Pop(top);
                        printf("\n������������ջΪ:");
                        Print();
                        }break;
                case 4: {
                        printf("\n���ջΪ:");
                        Print();
                        if(top!=NULL)
                            printf("\nջ��Ԫ���ǣ�%d\n",GetStackTop(top));
                        else
                            printf("\nջ�ǿյģ�û��Ԫ�أ�");
                        }break;
                case 5:{
                        exit(0);
                        }break;

                }
}while(choose<=5);


    return 0;
}
