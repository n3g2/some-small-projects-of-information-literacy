/*************************************************************************
	> File Name: main.cpp
	> Author: wangning
	> Mail: 201207wangning@edu2act.org
	> Created Time: 2013年09月12日 星期四 14时40分43秒
 ************************************************************************/
#include <iostream>
#include "scoreManage.h"

using namespace std;

int main()
{
    char choice;
    StudentNode *aHead = NULL;
    int flag = 0;

    aHead = creatList();

    while(1)
    {
        choice = viewMenu();
        switch(choice)
        {
            case 'A':
                if(insertStudentNode(aHead))
                {
                    break;
                }
                else
                {
                    return 0;
                }
            case 'D':
                deleteRecordFromList(aHead);
                break;
            case 'M':
                findAndEdit(aHead);
                break;
            case 'P':
                printList(aHead);
                break;
            case 'Q':
                return 0;
                break;
        }
    }

    cout << "系统退出！" << endl;
    return 0;
}
