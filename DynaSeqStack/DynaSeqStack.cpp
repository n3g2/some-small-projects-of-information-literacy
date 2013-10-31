/***
*DynaSeqStack.cpp - 动态顺序栈，即栈的动态顺序存储实现
*
*
*题目：实验3-1 栈的动态顺序存储实现
*
*	
****/

#include <iostream>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaSeqStack.h"

#define OVERFLOW 0
#define OK 1
#define FALSE 0
#define TRUE 1

using namespace std;

const int STACK_INIT_SIZE = 100;	// 初始分配的长度
const int STACKINCREMENT  = 10;		// 分配内存的增量

/*------------------------------------------------------------
操作目的：	初始化栈
初始条件：	无
操作结果：	构造一个空的栈
函数参数：
		SqStack *S	待初始化的栈
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool InitStack(SqStack *S)
{	
	//if( S -> base ) delete[] S -> base;
	if( ! (S -> base = new ElemType[STACK_INIT_SIZE]) ) return OVERFLOW;
	S -> stacksize = STACK_INIT_SIZE;
	S -> top = S -> base;
	return OK;
}

/*------------------------------------------------------------
操作目的：	销毁栈
初始条件：	栈S已存在
操作结果：	销毁栈S
函数参数：
		SqStack *S	待销毁的栈
返回值：
		无
------------------------------------------------------------*/
void DestroyStack(SqStack *S)
{
	free(S -> base);
	S -> top = S -> base = NULL;
}

/*------------------------------------------------------------
操作目的：	判断栈是否为空
初始条件：	栈S已存在
操作结果：	若S为空栈，则返回true，否则返回false
函数参数：
		SqStack S	待判断的栈
返回值：
		bool		是否为空
------------------------------------------------------------*/
bool StackEmpty(SqStack S)
{	
	return S.base == S.top;
}

/*------------------------------------------------------------
操作目的：	得到栈的长度
初始条件：	栈S已存在
操作结果：	返回S中数据元素的个数
函数参数：
		SqStack S	栈S
返回值：
		int			数据元素的个数
------------------------------------------------------------*/
int StackLength(SqStack S)
{	
	return S.top - S.base;
}

/*------------------------------------------------------------
操作目的：	得到栈顶元素
初始条件：	栈S已存在
操作结果：	用e返回栈顶元素
函数参数：
		SqStack S	栈S
		ElemType *e	栈顶元素的值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool GetTop(SqStack S, ElemType *e)
{
	if(S.base == S.top) return FALSE;
	*e = *(S.top - 1);
	return TRUE;
}

/*------------------------------------------------------------
操作目的：	遍历栈
初始条件：	栈S已存在
操作结果：	依次对S的每个元素调用函数fp
函数参数：
		SqStack S		栈S
		void (*fp)()	访问每个数据元素的函数指针
返回值：
		无
------------------------------------------------------------*/
void StackTraverse(SqStack S, void (*fp)(ElemType))
{
	fp = &visit;
	ElemType *p = S.top;
	while(p > S.base) fp(*--p);
}

/*------------------------------------------------------------
操作目的：	压栈——插入元素e为新的栈顶元素
初始条件：	栈S已存在
操作结果：	插入数据元素e作为新的栈顶
函数参数：
		SqStack *S	栈S
		ElemType e	待插入的数据元素
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool Push(SqStack *S, ElemType e)
{
	
	if( S -> stacksize == S -> top - S -> base )
	{	
		ElemType *newBase;
		if( ! (newBase = (ElemType *)realloc(S -> base,(S -> stacksize + STACKINCREMENT) * sizeof(ElemType))) )	return OVERFLOW;
		S -> base = newBase;
		S -> top = S -> base + S -> stacksize;
		S -> stacksize = S -> stacksize + STACKINCREMENT;
	}
	*(S -> top++) = e;
	return TRUE;
}

/*------------------------------------------------------------
操作目的：	弹栈——删除栈顶元素
初始条件：	栈S已存在且非空
操作结果：	删除S的栈顶元素，并用e返回其值
函数参数：
		SqStack *S	栈S
		ElemType *e	被删除的数据元素值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool Pop(SqStack *S, ElemType *e)
{	
	if( S->base == S->top ) return FALSE;
	else if( S->stacksize > STACK_INIT_SIZE && S->stacksize - (S->top - S->base) == STACKINCREMENT - 1 )
	{	
		ElemType *newBase;
		*e = *(S->top-1);
		if( ! (newBase = (ElemType *)realloc(S -> base,( S -> stacksize - STACKINCREMENT) * sizeof(ElemType))) ) return OVERFLOW;
		S -> base = newBase;
		S -> stacksize = S -> stacksize - STACKINCREMENT;
		S -> top = S -> base + S -> stacksize;
		return OK;
	}
	*e = *(--S -> top);
	return OK;
}
