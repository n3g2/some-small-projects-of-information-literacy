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

    choice = viewMenu();

    switch(choice)
    {
        case 'A': StudentNode *creatList(void);
        case 'D': deleteRecordFromList(StudentNode *aHead);
        case 'P': printRecord();
        case 'M': findAndEdit(StudentNode *aHead);
        case 'Q': return 0;
    }



    return 0;
}
