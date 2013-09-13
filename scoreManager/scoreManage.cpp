/*************************************************************************
	> File Name: scoreManage.cpp(成绩管理函数原型文件)
	> Author: wangning
	> Mail: 201207wangning@edu2act.org
	> Created Time: 2013年09月12日 星期四 14时40分43秒
 ************************************************************************/
#include <iostream>

using namespace std;

char viewMenu()
{
    char choice;

    cout << "欢迎使用成绩管理系统-v0.1" << endl << endl;

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
