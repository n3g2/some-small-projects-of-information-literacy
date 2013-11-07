/***
*DynaLnkQueue.h - 动态链式队列的定义
*	
****/

#if !defined(DYNALNKQUEUE_H)
#define DYNALNKQUEUE_H

#include "ElemType.h"

/*------------------------------------------------------------
// 链式队列结构的定义
------------------------------------------------------------*/

typedef struct Node
{
	ElemType data;				// 元素数据
	struct Node *next;			// 链式队列中结点元素的指针
} QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;				// 队列头指针
	QueuePtr rear;				// 队列尾指针
} LinkQueue;

/*------------------------------------------------------------
// 链式队列的基本操作
------------------------------------------------------------*/

bool InitQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);
bool QueueEmpty(LinkQueue Q);
int  QueueLength(LinkQueue Q);
bool GetHead(LinkQueue Q, ElemType *e);
void QueueTraverse(LinkQueue Q, void (*fp)(ElemType));
void ClearQueue(LinkQueue *Q);
bool EnQueue(LinkQueue *Q, ElemType e);
bool DeQueue(LinkQueue *Q, ElemType *e);

#endif
