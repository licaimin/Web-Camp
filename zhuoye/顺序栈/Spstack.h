
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
Status InitStack(SqStack *S);


/**ȡջ��Ԫ��
*
*
**/
Status GetTop(SqStack *S,SElemType *e);

/**ջ�Ĳ���
*
*
**/
Status Push(SqStack *S,SElemType e);

/**ջ��ɾ��
*
*
**/
Status Pop(SqStack *S,SElemType *e);

/**����һ��˳��ջ
*
*
**/
void build(SqStack*S);

/**��ӡ˳��ջ
*
*
**/
void Print(SqStack*S);
