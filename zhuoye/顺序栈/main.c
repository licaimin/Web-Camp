#include <stdio.h>
#include <stdlib.h>
#include "Spstack.h"
                             //ͨ����ϰ����������top=0��ʾ��ջ������C������������±�Լ����0��ʼ������C����������ʱ������趨������ܴ󲻱㣻��һ���棬����ջ��ʹ�ù������������ռ�Ĵ�С���ѹ��ƣ���ˣ�һ����˵���ڳ�ʼ�����ջʱ��Ӧ�޶�ջ�����������һ���Ϻ���������ǣ���Ϊջ����һ������������Ȼ����Ӧ�ù����У���ջ�Ŀռ䲻��ʹ��ʱ���������Ϊ�ˡ����趨����������STACK_INIT_SIAE(�洢�ռ��ʼ������)��STACKKINCREMENT(�洢�ռ��������


int main()
{

     SqStack S;
     int e,choose,data;
     do{
        printf("\n");
        printf("\n");
        printf("\n      ���˵�     \n");
        printf("\n   1 ����һ��ջ  \n");
        printf("\n   2 ��ȡջ��Ԫ�� \n");
        printf("\n   3 �����µ�ջ��Ԫ��  \n");
        printf("\n   4 ɾ��ջ��Ԫ��  \n");
        printf("\n   5 �˳�����  \n");
        printf("\n-------------------\n");
        printf("��ѡ������Ҫ�Ĺ���");
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
                    printf("����������Ҫ�������ֵ");
                    scanf("%d",&data);
                    Push(&S,data);
                    printf("�����µ�ջ��Ԫ��֮��");
                    Print(&S);
                }break;

        case 4:
                {
                    Pop(&S,e);
                    printf("ɾ��ջ��Ԫ��֮��");
                    Print(&S);
                }break;

        case 5:
                {
                    printf("ллʹ��");
                    exit(0);
                }break;

        }
       } while (choose<=5);

    return 0;

}
