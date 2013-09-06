/*
    ���ܣ��������㺯��
    ���ߣ�wangning
    ���ڣ�2013-9-5
*/
#include <iostream>
#include <stdio.h>

using namespace std;

void addition()
{
	int a;
	int b;
   
    	cout << "���������мӷ�����������������֮���ÿո��ָ���";
    	scanf("%d %d",&a,&b);
    	cout << "���������ĺ�Ϊ��" << a + b << endl;
    
	return;
}

void subtraction()
{	
	int a;
	int b;
	
	cout << "���������м�������������������֮���ÿո��ָ���";
	scanf("%d %d",&a,&b);
    	cout << "���������Ĳ�Ϊ��" << a - b << endl;
   
	return;
}

void multiplication()
{
	int a;
	int b;
	
	cout << "���������г˷�����������������֮���ÿո��ָ���";
	scanf("%d %d",&a,&b);
	cout << "���������Ļ�Ϊ��" << a * b << endl;
   
	return;
}

void division()
{	
	int a;
	int b;
	
	do
	{
		cout << "������Ҫ���г�������������������֮���ÿո�������";
		scanf("%d %d",&a,&b);

		if(b == 0)
		{	
			cout << "��������Ϊ�㣬����������!" << endl;
		}		
		else break;		
	}while(1);
	cout << "������������Ϊ��" << a * 1.0 / b << endl;
	
	return;
}
