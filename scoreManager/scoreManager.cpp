/*************************************************************************
	> File Name: scoreManage.cpp(成绩管理函数原型文件)
	> Author: wangning
	> Mail: 201207wangning@edu2act.org
	> Created Time: 2013年09月12日 星期四 14时40分43秒
 ************************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "scoreManager.h"

using namespace std;

//显示菜单
char viewMenu()
{
    char choice;

	cout << endl;
    cout << "              ================欢迎使用成绩管理系统-v0.1==========" << endl << endl;

    cout << "              -请选择您要进行的操作:                             " << endl;
    cout << "              ---------------------------------------------------"<< endl;
    cout << "              -       添加请按：A               删除请按：D     -" << endl;
    cout << "              -       打印请按：P               修改请按：M     -" << endl;
    cout << "              -       退出请按：Q                               -" << endl;
    cout << "              ---------------------------------------------------" << endl << endl;

    cout << "^_^请选择您的操作：";
    cin >> choice;

    return choice;
}

//创建链表
StudentNode *creatList(void)
{
    StudentNode *aHead = NULL;

    aHead = (StudentNode *) malloc(sizeof(StudentNode));
	aHead -> ID = 0;
	strcpy(aHead -> stuName,"stuHead");
	aHead -> subLists = NULL;
    aHead -> next = NULL;

    return aHead;
}

//插入成绩
int insertStudentNode(StudentNode *aHead)
{
    int subNum;      //学科数目
    swapSub *tempSub = NULL;
    int i;

    cout << "请输入此次要插入信息的学科数目：";
    cin >> subNum;
	fflush(stdin);

    tempSub = (swapSub *)malloc(sizeof(swapSub) * subNum);

    if(!tempSub)
    {
        cout << "开辟临时科目内存时失败，程序退出！" << endl;
        return 0;
    }
    for(i = 0; i < subNum; i++)
    {
        cout << "请输入第" << i + 1 << "个科目名称:";
		gets(tempSub[i].subName);
		fflush(stdin);
    }

    StudentNode *p = aHead;
    SubjectNode *q = NULL;
    char continueInsert;
	int j;

    do
    {
        while (p -> next )  //Find the last node
		{
			p = p -> next;
		}
        p -> next = (StudentNode *)malloc(sizeof(StudentNode));
		p = p -> next;
        if(!p)
        {
            cout << "开辟新学生节点内存时失败，程序退出！";
            return 0;
        }
		p -> next = NULL;

        q = p -> subLists = (SubjectNode *) malloc(sizeof(SubjectNode) * subNum);
        if(!q)
        {
            cout << "开辟学生科目内存时失败！";
            return 0;
        }

		//为学科列表的科目名称区赋值
        for(i = 0; i < subNum; i++ )
        {
            strcpy(q[i].subName,tempSub[i].subName);
        }

        cout << "请输入要插入的信息：" << endl;
        cout << "学号：";
        cin >> p -> ID;
        cout << "姓名：";
        cin >> p -> stuName;
		for(i = 0; i < subNum; i++)
		{
			cout << q[i].subName << ":";
			cin >> q[i].subScore;
			fflush(stdin);
		}

        cout << "请核对新插入的学生信息：" << endl;
        cout << "学号:" << p -> ID;
        cout << " 姓名:" << p -> stuName;
		for(i = 0; i < subNum; i++)
		{
			cout << " " << q[i].subName << ":";
			cout << q[i].subScore;
		}

        cout << endl << "继续插入请按I，退出请按其他字母键：";
        cin >> continueInsert;
		fflush(stdin);

    }while( 'I' ==  continueInsert );

    free(tempSub);
	tempSub = NULL;

	system("cls");
    return 1;
}

//删除成绩
int deleteRecordFromList(StudentNode *aHead)
{

	return 0;
}

//修改成绩
int findAndEdit(StudentNode *aHead)
{
	return 0;
}

//查询成绩
int printList(StudentNode *aHead)
{
    StudentNode *p = aHead;
	SubjectNode *q = NULL;
	int i;

    while( p = p -> next )
    {
        cout << "学号:";
        cout << p -> ID;
        cout << " 姓名:";
        cout << p -> stuName;
		q = p -> subLists;
        for(i = 0; i < 2; i++)
		{
			cout << " " << q[i].subName << ":";
			cout << q[i].subScore;
		}
		cout << endl;
    }

	system("pause");
	system("cls");
	return 0;
}