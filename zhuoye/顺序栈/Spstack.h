
#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT  20//存储空间分配怎量
#define OVERFLOW -2
#define OK 1
#define ERROR 0


typedef int SElemType;//定义SElemType类型为int
typedef int Status;//定义Status类型为int

typedef struct {
    SElemType *base;//base可称为栈底指针，在顺序栈中，它始终指向栈底的位置，若base的值为NULL,则表明栈结构不存在
    SElemType *top;  //称top为栈顶指针，其初始值指向栈底，即top=base可作为栈空标记，每当插入新的栈顶元素时，指针top增1；删除栈顶元素时，指针top减1，因此，非空栈中的栈顶指针始终在栈顶元素的下一个位置上
    int       stacksize; // stacksize指示栈的当前可使用的最大容量
} SqStack;

/**栈的初始化
*
*
**/
Status InitStack(SqStack *S);


/**取栈顶元素
*
*
**/
Status GetTop(SqStack *S,SElemType *e);

/**栈的插入
*
*
**/
Status Push(SqStack *S,SElemType e);

/**栈的删除
*
*
**/
Status Pop(SqStack *S,SElemType *e);

/**建立一个顺序栈
*
*
**/
void build(SqStack*S);

/**打印顺序栈
*
*
**/
void Print(SqStack*S);
