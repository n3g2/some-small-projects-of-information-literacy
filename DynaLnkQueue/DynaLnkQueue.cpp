/***
*DynaLnkQueue.cpp - 动态链式队列，即队列的动态链式存储实现
*
*
*题目：实验4 队列的动态链式存储实现
*	
****/

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaLnkQueue.h"

#define FALSE 0
#define TRUE 1
#define OVERFLOW 0
#define OK 1

/*------------------------------------------------------------
操作目的：	初始化队列
初始条件：	无
操作结果：	构造一个空的队列
函数参数：
		LinkQueue *Q	待初始化的队列
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool InitQueue(LinkQueue *Q)//初始化带头结点的队列
{	
	if(! (Q -> rear = Q -> front = (QNode*)malloc(sizeof(QNode))) )	return OVERFLOW;
	Q -> front -> next = NULL;
	return OK;
}

/*------------------------------------------------------------
操作目的：	销毁队列
初始条件：	队列Q已存在
操作结果：	销毁队列Q
函数参数：
		LinkQueue *Q	待销毁的队列
返回值：
		无
------------------------------------------------------------*/
void DestroyQueue(LinkQueue *Q)
{
	QNode *p = Q -> front;
	while( Q -> front )
	{
		p = Q -> front -> next;
		free(Q -> front);
		Q -> front = p; 
	}
	Q -> front = Q -> rear = NULL;
}

/*------------------------------------------------------------
操作目的：	判断队列是否为空
初始条件：	队列Q已存在
操作结果：	若Q为空队列，则返回true，否则返回false
函数参数：
		LinkQueue Q		待判断的队列
返回值：
		bool			是否为空
------------------------------------------------------------*/
bool QueueEmpty(LinkQueue Q)
{	
	return Q.front == Q.rear;
}

/*------------------------------------------------------------
操作目的：	得到队列的长度
初始条件：	队列Q已存在
操作结果：	返回Q中数据元素的个数
函数参数：
		LinkQueue Q		队列Q
返回值：
		int				数据元素的个数
------------------------------------------------------------*/
int QueueLength(LinkQueue Q)
{	
	int i = 0;
	QNode *p = Q.front;
	while( p = p -> next) i++;
	return i;
}

/*------------------------------------------------------------
操作目的：	得到队列首元素
初始条件：	队列Q已存在
操作结果：	用e返回队列首元素
函数参数：
		LinkQueue Q		队列Q
		ElemType *e		队列首元素的值
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool GetHead(LinkQueue Q, ElemType *e)
{	
	if( !(Q.front -> next) ) return FALSE; 
	*e = Q.front -> next -> data;
	return OK;
}

/*------------------------------------------------------------
操作目的：	遍历队列
初始条件：	队列Q已存在
操作结果：	依次对Q的每个元素调用函数fp
函数参数：
		LinkQueue Q		队列Q
		void (*fp)()	访问每个数据元素的函数指针
返回值：
		无
------------------------------------------------------------*/
void QueueTraverse(LinkQueue Q, void (*fp)(ElemType))
{
	fp = &visit;
	QNode *walk = Q.front;
	while( walk = walk -> next) (*fp)(walk -> data);
}

/*------------------------------------------------------------
操作目的：	清空队列
初始条件：	队列Q已存在
操作结果：	将队列清空
函数参数：
		LinkQueue *Q	队列Q
返回值：
		无
------------------------------------------------------------*/
void ClearQueue(LinkQueue *Q)
{	
	QNode *next;
	QNode *clear = Q -> front -> next;
	Q -> front -> next = NULL;
	while( clear )
	{
		next = clear -> next;
		free(clear);
		clear = next;
	}
	Q -> rear = Q -> front;
}

/*------------------------------------------------------------
操作目的：	在队列末尾插入元素e
初始条件：	队列Q已存在
操作结果：	插入元素e作为队列新的尾结点
函数参数：
		LinkQueue *Q		队列Q
		ElemType e		待插入的数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool EnQueue(LinkQueue *Q, ElemType e)
{	
	QNode *p = Q -> front;
	QNode *newNode;
	if( !(newNode= (QNode *)malloc(sizeof(QNode))) ) return OVERFLOW;
	while( p -> next && (p = p -> next) );
	p -> next = newNode;
	newNode -> data = e;
	newNode -> next = NULL;
	Q -> rear = newNode;
	return OK;
}

/*------------------------------------------------------------
操作目的：	删除链式队列的头结点
初始条件：	队列Q已存在
操作结果：	删除链式队列的头结点
函数参数：
		LinkQueue *Q		队列Q
		ElemType *e		待插入的数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool DeQueue(LinkQueue *Q, ElemType *e)
{	
	QNode *delNode;
	if( !(delNode = Q -> front -> next) ) return FALSE;
	*e = delNode -> data;
	delNode -> next ? Q -> front -> next = delNode -> next : Q -> rear = Q -> front;
	free(delNode);
	return OK;
}
