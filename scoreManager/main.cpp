/*************************************************************************
	> File Name: main.cpp
	> Author: wangning
	> Mail: 201207wangning@edu2act.org
	> Created Time: 2013年09月12日 星期四 14时40分43秒
 ************************************************************************/
#include <iostream>
#include "scoreManagerTest.h"

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
                if( insertStudentNode(aHead) )
                {
                    break;
                }
                else
                {
                    return 0;
                }
		
				break;
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
			default:
				cout << "输入有误！" << endl;
        }
    }

    cout << "系统退出！" << endl;
    return 0;
}