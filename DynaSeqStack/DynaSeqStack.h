/***
*DynaSeqStack.h - 动态顺序栈的定义
*	
****/

#if !defined(DYNASEQSTACK_H)
#define DYNASEQSTACK_H

#include "ElemType.h"

/*------------------------------------------------------------
// 栈结构的定义
------------------------------------------------------------*/
typedef struct Stack
{
	ElemType *base;				// 栈基址
	ElemType *top;				// 栈顶
	int stacksize;				// 栈存储空间的尺寸
} SqStack;

/*------------------------------------------------------------
// 栈的基本操作
------------------------------------------------------------*/

bool InitStack(SqStack *S);
void DestroyStack(SqStack *S);
bool StackEmpty(SqStack S);
int  StackLength(SqStack S);
bool GetTop(SqStack S, ElemType *e);
void StackTraverse(SqStack S, void (*fp)(ElemType));
bool Push(SqStack *S, ElemType e);
bool Pop(SqStack *S, ElemType *e);

#endif /* DYNASEQSTACK_H */
