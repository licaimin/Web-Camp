
                             //ͨ����ϰ����������top=0��ʾ��ջ������C������������±�Լ����0��ʼ������C����������ʱ������趨������ܴ󲻱㣻��һ���棬����ջ��ʹ�ù������������ռ�Ĵ�С���ѹ��ƣ���ˣ�һ����˵���ڳ�ʼ�����ջʱ��Ӧ�޶�ջ�����������һ���Ϻ���������ǣ���Ϊջ����һ������������Ȼ����Ӧ�ù����У���ջ�Ŀռ䲻��ʹ��ʱ���������Ϊ�ˡ����趨����������STACK_INIT_SIAE(�洢�ռ��ʼ������)��STACKKINCREMENT(�洢�ռ��������
#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT  20//�洢�ռ��������
#define OVERFLOW -2
#define OK 1
#define ERROR 0


typedef int SElemType;//����SElemType����Ϊint
typedef int Status;//����Status����Ϊint

typedef struct {
    SElemType *base;//base�ɳ�Ϊջ��ָ�룬��˳��ջ�У���ʼ��ָ��ջ�׵�λ�ã���base��ֵΪNULL,�����ջ�ṹ������
    SElemType *top;  //��topΪջ��ָ�룬���ʼֵָ��ջ�ף���top=base����Ϊջ�ձ�ǣ�ÿ�������µ�ջ��Ԫ��ʱ��ָ��top��1��ɾ��ջ��Ԫ��ʱ��ָ��top��1����ˣ��ǿ�ջ�е�ջ��ָ��ʼ����ջ��Ԫ�ص���һ��λ����
    int       stacksize; // stacksizeָʾջ�ĵ�ǰ��ʹ�õ��������
} SqStack;
/**ջ�ĳ�ʼ��
*
*
**/
Status InitStack(SqStack *S){  //����һ����ջ
    S->base=(SElemType *)malloc(STACK_INIT_SIZE *sizeof(SElemType));
    if(!S->base)
        exit(OVERFLOW);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}

/**ȡջ��Ԫ��
*
*
**/
Status GetTop(SqStack *S,SElemType *e){  //��ջ���գ���e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
     if(S->top==S->base)
        return ERROR;
     e=*(S->top-1);
     printf("ջ��Ԫ��ֵ:%d\n",e);
      return OK;
}

/**ջ�Ĳ���
*
*
**/
Status Push(SqStack *S,SElemType e){  //����Ԫ��eΪ�µ�ջ��Ԫ��
     if(S->top-S->base>=S->stacksize){ //ջ����׷�Ӵ洢�ռ�
            S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!S->base)
        exit(OVERFLOW);  //�洢����ʧ��
      S->top=S->base+S->stacksize;
       S->stacksize+=STACKINCREMENT;
     }
        *S->top++=e;
         return OK;
 }

/**ջ��ɾ��
*
*
**/
Status Pop(SqStack *S,SElemType *e){ //��ջ���գ���ɾ��Sջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
     if(S->top==S->base)
            return ERROR;
      e=*--S->top;
      printf("ɾ��ջ��Ԫ��ֵ:%d\n",e);
      return OK;
}

/**����һ��˳��ջ
*
*
**/
void build(SqStack*S){
         int i,n;  printf("����Ԫ�ظ���:");
         scanf("%d",&n);
         printf("��������Ԫ��:");
         for(i=0;i<n;i++){
                scanf("%d",S->top);
                S->top++;
        }
}

/**��ӡ˳��ջ
*
*
**/
void Print(SqStack*S) {
          int i,n;
          n=S->top-S->base;
          printf("ջ��Ԫ��ֵ:");
          for(i=1;i<=n;i++){
                printf("%d ",*(S->top-i));
           }
          printf("\n");
}
