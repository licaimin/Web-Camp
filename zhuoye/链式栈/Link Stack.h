
#define true 1
#define false 0


typedef int SElemType;
typedef int Status;

typedef struct StackNode{
        SElemType data;
        struct StackNode *next;
}StackNode, *LinkStackPtr;

LinkStackPtr top;
/**插入元素e为新的栈顶元素
*
*
**/
Status Push(LinkStackPtr top,SElemType e);

/**若栈不为空，则删除栈顶元素
*
*
**/
Status Pop(LinkStackPtr top);

/**获取栈顶元素
*
*
**/
Status GetStackTop(LinkStackPtr top);

/**判断栈是否为空
*
*
**/
Status IsEmpty();

/**打印链式栈
*
*
**/
void Print();
