#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DynaSeqStack.h"

const int STACK_INIT_SIZE = 100; 	// 初始分配的长度
const int STACKINCREMENT  = 10;		// 分配内存的增量

using namespace std;

void view()
{
	cout << "        --------------------栈模拟------------------------" << endl;
	cout << "        =            I:初始化一个很栈                     =" << endl;
	cout << "        =            D:销毁栈                            =" << endl;
	cout << "        =            E:判断栈是否为空                     =" << endl;
	cout << "        =            P:压栈--插入元素e为新的栈顶元素        =" << endl;
	cout << "        =            T:得到栈顶元素                       =" << endl;
	cout << "        =            L:获得当前栈的长度(有效元素个数)       =" << endl;
	cout << "        =            S:遍历栈                            =" << endl;
	cout << "        =            O:弹栈--删除栈顶元素                 =" << endl;
	cout << "        =            Q:退出程序                          =" << endl;
	cout << "        -------------------------------------------------" << endl;
	cout << "^_^请选择:";
}

int main()
{
	SqStack stackTest;
	ElemType e;
	void (*fp)(ElemType) = &visit;
	char choice;
	stackTest.top = stackTest.base = NULL;
		
	while(true)
	{	
		system("cls"); //only for windows
		view();
		cin >> choice;
		fflush(stdin);

		if('I' == choice)
		{
			//bool InitStack(SqStack *S);
			if( InitStack(&stackTest) )
			{
				cout << "栈初始化成功! ^_^" << endl;	
				cout << "按任意键继续...";
				getchar();
				fflush(stdin);
			}
			else
			{	
				cout << "初始化失败!" << endl;
				cout << "按任意键退出程序!";
				getchar();
				return 0;
			}	
		}
		else if('D' == choice)
		{
			//void DestroyStack(SqStack *S);
			DestroyStack(&stackTest);
			cout << "销毁栈成功! ^_^" << endl;
			cout << "按任意键继续...";
			getchar();
			fflush(stdin);
		}
		else if('E' == choice)
		{
			//bool StackEmpty(SqStack S);
			if( StackEmpty(stackTest) )
			{
				cout << "栈为空" << endl;
			}
			else 
			{
				cout << "栈不为空" << endl;
			}
			cout << "按任意键继续...";
			getchar();
			fflush(stdin);
		}
		else if('L' == choice)
		{
			//int  StackLength(SqStack S);
			cout << "当前栈的长度为:" << StackLength(stackTest) << endl;
			cout << "按任意键继续...";
			getchar();
			fflush(stdin);
		}
		else if('T' == choice)
		{
			//bool GetTop(SqStack S, ElemType *e);
			if( GetTop(stackTest,&e) )
			{
				cout << "栈顶元素为:" << e << endl;
			}
			else
			{
				cout << "栈为空，无栈顶元素" << endl;
			}
			cout << "按任意键继续...";
			getchar();
			fflush(stdin);
		}
		else if('S' == choice)
		{
			//void StackTraverse(SqStack S, void (*fp)(ElemType));
			StackTraverse(stackTest,fp);
			cout << "按任意键继续...";
			getchar();
			fflush(stdin);
		}
		else if('P' == choice)
		{
			cout << "请输入要压入栈顶的元素:";
			cin >> e;
			fflush(stdin);

			//bool Push(SqStack *S, ElemType e);
			if( Push(&stackTest,e) )
			{
				cout << "压栈成功!" << endl;
				cout << "按任意键继续...";
				getchar();
				fflush(stdin);
			}
			else 
			{	
				cout << "压栈失败!" << endl;
				cout << "按任意键退出程序!";
				getchar();
				return 0;
			}
		}	
		else if('O' == choice)
		{
			//bool Pop(SqStack *S, ElemType *e);
			if( Pop(&stackTest,&e) )
			{
				cout << "被删除栈顶元素的值为:" << e << endl;
				cout << "按任意键继续...";
				getchar();
				fflush(stdin);
			}
			else 
			{
				cout << "弾栈失败!" << endl;
				cout << "按任意键退出程序!";
				getchar();
				return 0;
			}
			
		}
		else if('Q' == choice)
		{
			return 0;
		}
		else
		{
			cout << "输入错误!" << endl;
			cout << "按任意键继续...";
			getchar();
			fflush(stdin);
		}
	}

	return 0;
}
