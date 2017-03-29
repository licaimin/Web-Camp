
#define true 1
#define false 0


typedef int SElemType;
typedef int Status;

typedef struct StackNode{
        SElemType data;
        struct StackNode *next;
}StackNode, *LinkStackPtr;

LinkStackPtr top;//����һ��ջ��ָ��


/**����Ԫ��eΪ�µ�ջ��Ԫ��
*
*
**/
Status Push(LinkStackPtr top,SElemType e){//e��ʾ��ջ��Ԫ��
        LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));   //��Ԫ��ֵΪe���½����s
        s->data= e;
        s->next=top;  //�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��
        top=s;
return top;
}

/**��ջ��Ϊ�գ���ɾ��ջ��Ԫ��
*
*
**/
Status Pop(LinkStackPtr top){
	LinkStackPtr p;
	if(top!=NULL){
		p=top;
		top=top->next;
		free(p);
		printf("��ջ�����!\n");
		return top;
}
    else
    printf("ջ�ǿյģ��޷���ջ\n");
    return 0;
}
/**��ȡջ��Ԫ��
*
*
**/
Status GetStackTop(LinkStackPtr top){
		return top->data;
}

/**�ж�ջ�Ƿ�Ϊ��
*
*
**/

Status IsEmpty(){
		return top==NULL? true:false;
}

/**��ӡ��ʽջ
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
