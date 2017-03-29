
                             //通常的习惯做法是以top=0表示空栈，鉴于C语言中数组的下标约定从0开始，则当以C作描述语言时，如此设定会带来很大不便；另一方面，由于栈的使用过程中所需最大空间的大小很难估计，因此，一般来说，在初始化设空栈时不应限定栈的最大容量。一个较合理的做法是：先为栈分配一个基本容量，然后再应用过程中，当栈的空间不够使用时再逐段扩大。为此。可设定两个常量：STACK_INIT_SIAE(存储空间初始分配量)和STACKKINCREMENT(存储空间分配增量
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
Status InitStack(SqStack *S){  //构造一个空栈
    S->base=(SElemType *)malloc(STACK_INIT_SIZE *sizeof(SElemType));
    if(!S->base)
        exit(OVERFLOW);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}

/**取栈顶元素
*
*
**/
Status GetTop(SqStack *S,SElemType *e){  //若栈不空，用e返回S的栈顶元素，并返回OK，否则返回ERROR
     if(S->top==S->base)
        return ERROR;
     e=*(S->top-1);
     printf("栈顶元素值:%d\n",e);
      return OK;
}

/**栈的插入
*
*
**/
Status Push(SqStack *S,SElemType e){  //插入元素e为新的栈顶元素
     if(S->top-S->base>=S->stacksize){ //栈满，追加存储空间
            S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!S->base)
        exit(OVERFLOW);  //存储分配失败
      S->top=S->base+S->stacksize;
       S->stacksize+=STACKINCREMENT;
     }
        *S->top++=e;
         return OK;
 }

/**栈的删除
*
*
**/
Status Pop(SqStack *S,SElemType *e){ //若栈不空，则删除S栈顶元素，用e返回其值，并返回OK，否则返回ERROR
     if(S->top==S->base)
            return ERROR;
      e=*--S->top;
      printf("删除栈顶元素值:%d\n",e);
      return OK;
}

/**建立一个顺序栈
*
*
**/
void build(SqStack*S){
         int i,n;  printf("输入元素个数:");
         scanf("%d",&n);
         printf("依次输入元素:");
         for(i=0;i<n;i++){
                scanf("%d",S->top);
                S->top++;
        }
}

/**打印顺序栈
*
*
**/
void Print(SqStack*S) {
          int i,n;
          n=S->top-S->base;
          printf("栈的元素值:");
          for(i=1;i<=n;i++){
                printf("%d ",*(S->top-i));
           }
          printf("\n");
}
