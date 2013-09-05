/*
    功能：四则运算函数
    作者：wangning
    日期：2013-9-5
*/
#include <iostream>
#include <stdio.h>

using namespace std;

void addition()
{
    int a;
    int b;
   
	cout << "请输入进行加法的两个数，两个数之间用空格分隔：";
    scanf("%d %d",&a,&b);
    cout << "这两个数的和为：" << a + b << endl;
    
	return;
}

void subtraction()
{	
	int a;
	int b;
	
	cout << "请输入进行减法的两个数，两个数之间用空格分隔：";
	scanf("%d %d",&a,&b);
    cout << "这两个数的差为：" << a - b << endl;
   
	return;
}

void multiplication()
{
	int a;
	int b;
	
	cout << "请输入进行乘法的两个数，两个数之间用空格分隔：";
	scanf("%d %d",&a,&b);
    cout << "这两个数的积为：" << a * b << endl;
   
	return;
}

void division()
{	
	int a;
	int b;
	
	do
	{
		cout << "请输入要进行除法的两个数，两个数之间用空格隔开：";
		scanf("%d %d",&a,&b);

		if(b == 0)
		{	
			cout << "除数不能为零，请重新输入!" << endl;
		}		
		else break;		
	}while(1);
	cout << "这两个数的商为：" << a * 1.0 / b << endl;
	
	return;
}
