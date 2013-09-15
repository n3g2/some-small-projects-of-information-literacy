/*************************************************************************
	> File Name: scoreManage.cpp(成绩管理函数原型文件)
	> Author: wangning
	> Mail: 201207wangning@edu2act.org
	> Created Time: 2013年09月12日 星期四 14时40分43秒
 ************************************************************************/
#include <iostream>
#include <stdlib.h>  //malloc函数
#include <string.h>
#include "scoreManage.h"

using namespace std;

//显示菜单
char viewMenu()
{
    char choice;

    cout << endl << "欢迎使用成绩管理系统-v0.1" << endl << endl;

    cout << "请选择您要进行的操作:" << endl;
    cout << "----------------------------------"<< endl;
    cout << "添加请按：A" << "   " << "删除请按：D" << endl;
    cout << "打印请按：P" << "   " << "修改请按：M" << endl;
    cout << "退出请按：Q" << endl;
    cout << "----------------------------------"<< endl << endl;

    cout << "请选择您的操作：";
    cin >> choice;

    return choice;
}

//创建链表
StudentNode *creatList(void)
{
    StudentNode *aHead = NULL;

    aHead = (StudentNode *) malloc(sizeof(StudentNode));
    strcpy(aHead -> stuName,"学生头");
    aHead -> next = NULL;

    return aHead;
}

//插入成绩
int insertStudentNode(StudentNode *aHead)
{
    int subNum;      //学科数目
    string *subNames = NULL;
    int i;


    cout << "请输入此次要插入信息的学科数目：";
    cin >> subNum;

    subNames = new string[subNum];
    if(!subNames)
    {
        cout << "开辟临时科目内存时失败，程序退出！" << endl;
        return 0;
    }
    for(i = 0; i < subNum; i++)
    {
        cout << "请输入第" << i + 1 << "个科目名称:";
        cin >> subNames[i];
    }

    StudentNode *p = aHead;
    SubjectNode *q = NULL;
    string continueInsert;

    do
    {
        while( p = p -> next );   //Find the last node
        p = (StudentNode *)malloc(sizeof(StudentNode));
        if(!p)
        {
            cout << "开辟新学生节点内存时失败，程序退出！";
            return 0;
        }
        q = p -> subLists;   //q指向学科列表

        cout << sizeof(SubjectNode);
        q = (SubjectNode *) malloc(sizeof(SubjectNode));
        if(!q)
        {
            cout << "开辟学生科目内存时失败！";
            return 0;
        }

        strcpy(q -> subName,"学生科目头");
        q -> subScore = -1;
        cout << q -> subName << q ->subScore;


        while(q = q -> next );
        for(i = 0; i < subNum; i++ )
        {
            q = (SubjectNode *) malloc(sizeof(SubjectNode));
            if(!q)
            {
                cout << "开辟学生科目内存时失败！";
                return 0;
            }
            strcpy(q -> subName,subNames[i].c_str());
            q = q -> next;
        }

        q = p -> subLists;   //q指向学科列表
        while(q = q -> next)
        {
            cout << q -> subName << endl;
        }



        //为学科列表的科目名称区赋值
       // for(i = 0; i < subNum; i++)
        //{
         //   strcpy(q[i].subName,subNames[i].c_str());
        //}





        cout << "请输入要插入的信息：" << endl;
        cout << "学号：";
        cin >> p -> ID;
        cout << "姓名：";
        cin >> p -> stuName;


       // q = p -> subLists;   //q指向学科列表
      //  while(q = q -> next)
      //  {
      //      cout << q ->subName << endl;
      //      cin >> q -> subScore;
        //}


        cout << "请核对新插入的学生信息：" << endl;
        cout << "学号:" << p -> ID;
        cout << " 姓名:" << p -> stuName;
        q = p -> subLists;   //q指向学科列表
        while(q = q -> next)
        {
            cout << q ->subName << endl;
            cin >> q -> subScore;
        }


        cout << endl << "继续插入请按I，退出请按其他字母键：";
        cin >> continueInsert;
    }while( "I" == continueInsert );

    delete[] subNames;

    return 1;
}

//删除成绩
int deleteRecordFromList(StudentNode *aHead)
{

}

//修改成绩
int findAndEdit(StudentNode *aHead)
{

}

//查询成绩
int printList(StudentNode *aHead)
{
    StudentNode *p = aHead;

    while( p = p -> next )
    {
        cout << "学号:";
        cout << p -> ID;
        cout << "姓名:";
        cout << p -> stuName;
       // for(i = 0; i < )
    }
}
