
#define true 1
#define false 0


typedef int SElemType;
typedef int Status;

typedef struct StackNode{
        SElemType data;
        struct StackNode *next;
}StackNode, *LinkStackPtr;

LinkStackPtr top;
/**����Ԫ��eΪ�µ�ջ��Ԫ��
*
*
**/
Status Push(LinkStackPtr top,SElemType e);

/**��ջ��Ϊ�գ���ɾ��ջ��Ԫ��
*
*
**/
Status Pop(LinkStackPtr top);

/**��ȡջ��Ԫ��
*
*
**/
Status GetStackTop(LinkStackPtr top);

/**�ж�ջ�Ƿ�Ϊ��
*
*
**/
Status IsEmpty();

/**��ӡ��ʽջ
*
*
**/
void Print();
