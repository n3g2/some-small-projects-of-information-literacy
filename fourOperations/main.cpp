/*************************************************************************
	> File Name: main.cpp
	> Author: wangning
	> Mail: 201207wangning@edu2act.org
	> Created Time: 2013年09月05日 星期四 14时40分43秒
 ************************************************************************/
#include <iostream>
#include "fourOperations.h"

using namespace std;

int main()
{
    char choice;

    cout << "\n欢迎使用四则运算小程序\n" << endl;
   
	while(1)
	{
		cout << "\n请选择操作类型:" << endl;
		cout << "A:加法运算" << endl;
		cout << "S:减法运算" << endl;
		cout << "M:乘法运算" << endl;
		cout << "D:除法运算" << endl;
		cout << "Q:退出程序运行" << endl;

		cout << "请选择您的操作：";
		cin >> choice;
		fflush(stdin);

		switch(choice)
		{
			case 'A': 
				addition();

				system("pause");
				fflush(stdin);			
				break;
			case 'S': 
				subtraction();

				system("pause");
				fflush(stdin);	
				break;
			case 'M':
				multiplication();

				system("pause");
				fflush(stdin);	
				break;
			case 'D': 
				division();

				system("pause");
				fflush(stdin);	
				break;
			case 'Q': return 0;

			default: 
				cout << "\n**********输入有误，请重新输入！************\n" << endl;
		}
	}

    return 0;
}
