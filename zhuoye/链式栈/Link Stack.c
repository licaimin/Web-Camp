
#define true 1
#define false 0


typedef int SElemType;
typedef int Status;

typedef struct StackNode{
        SElemType data;
        struct StackNode *next;
}StackNode, *LinkStackPtr;

LinkStackPtr top;//定义一个栈顶指针


/**插入元素e为新的栈顶元素
*
*
**/
Status Push(LinkStackPtr top,SElemType e){//e表示入栈的元素
        LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));   //设元素值为e的新结点是s
        s->data= e;
        s->next=top;  //把当前的栈顶元素赋值给新结点的直接后继
        top=s;
return top;
}

/**若栈不为空，则删除栈顶元素
*
*
**/
Status Pop(LinkStackPtr top){
	LinkStackPtr p;
	if(top!=NULL){
		p=top;
		top=top->next;
		free(p);
		printf("退栈已完成!\n");
		return top;
}
    else
    printf("栈是空的，无法退栈\n");
    return 0;
}
/**获取栈顶元素
*
*
**/
Status GetStackTop(LinkStackPtr top){
		return top->data;
}

/**判断栈是否为空
*
*
**/

Status IsEmpty(){
		return top==NULL? true:false;
}

/**打印链式栈
*
*
**/
void Print(){
		StackNode *p;
		p=top;
		if(IsEmpty()){
			printf("the stack is empty");
			return;
		}
		while(p){
			printf("%4d",p->data);
			p=p->next;
		}
		printf("\n");
}
