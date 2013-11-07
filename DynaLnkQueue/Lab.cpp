#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DynaLnkQueue.h"

using namespace std;

void view()
{
	cout << "         ===================队列模拟=================" << endl;
	cout << "         -               I:初始化队列                -" << endl;
	cout << "         -               D:销毁队列                  -" << endl;
	cout << "         -               E:判断队列是否为空           -" << endl;
	cout << "         -               L:获得得列长度              -" << endl;
	cout << "         -               H:获得队列首元              -" << endl;
	cout << "         -               T:遍历队列                  -" << endl;
	cout << "         -               C:清空队列                  -" << endl;
	cout << "         -               P:进队一个元素              -" << endl;
	cout << "         -               O:出队一个元素              -" << endl;
	cout << "         ===========================================" << endl;
	cout << "请选择^_^：";
}

int main()
{	
	LinkQueue *aQ = NULL;
	char choice;
	ElemType e;
	void (*fp)(ElemType) = &visit;
	
	if( !(aQ = (LinkQueue *)malloc(sizeof(LinkQueue))) )	return 0;

	while(true)
	{	
		cout << "Press any key to continue...";
		getchar();
		system("cls");	//only for windows

		view();
		cin >> choice;
		fflush(stdin);

		if('I' == choice)
		{
			//bool InitQueue(LinkQueue *Q);
			while( ! InitQueue(aQ) );
			cout << "初始化成功! ^_^" << endl;
		}
		else if('D' == choice)
		{
			//void DestroyQueue(LinkQueue *Q);
			DestroyQueue(aQ);
			cout << "销毁队列成功! ^_^" << endl;
		}
		else if('E' == choice)
		{
			//bool QueueEmpty(LinkQueue Q);
			QueueEmpty(*aQ) ? cout << "队列为空!" << endl : cout << "队列不为空!" << endl;
		}
		else if('L' == choice)
		{
			//int QueueLength(LinkQueue Q);
			cout << "队列长度为:" << QueueLength(*aQ) << endl;
		}
		else if('H' == choice)
		{
			//bool GetHead(LinkQueue Q, ElemType *e);
			GetHead(*aQ, &e) ? cout << "队列首元素为:" << e << endl : cout << "当前队列无首元!" << endl;	
		}
		else if('T' == choice)
		{
			//void QueueTraverse(LinkQueue Q, void (*fp)(ElemType));
			QueueTraverse(*aQ,fp);
		}
		else if('C' == choice)
		{
			//void ClearQueue(LinkQueue *Q);
			ClearQueue(aQ);
			cout << "清空列队成功! ^_^" << endl;
		}
		else if('P' == choice)
		{
			//bool EnQueue(LinkQueue *Q, ElemType e);
			cout << "请输入要入队的元素:";
			cin >> e;
			fflush(stdin);
			EnQueue(aQ,e) ? cout << "入队成功! ^_^" << endl : cout << "入队失败! -_-|" << endl;
		}
		else if('O' == choice)
		{
			//bool DeQueue(LinkQueue *Q, ElemType *e);
			DeQueue(aQ,&e) ? cout << e << "出队成功! ^_^" << endl : cout << "当前队列为空，出兑失败! -_-|" << endl;
		}
		else if('Q' == choice)
		{
			return 0;
		}
		else 
		{
			cout << "输入有误! -_-|" << endl;
		}
	}
}
