#ifndef SCOREMANAGE_H_INCLUDED
#define SCOREMANAGE_H_INCLUDED

typedef struct StudentNode
{
    char name[30];  /* 姓名*/
    int mathScore;  /* 数学成绩*/
    int engScore;   /* 英语成绩*/
    struct StudentNode *next;   /* 下一个成绩结点指针*/
}StudentNode;

//显示菜单
char viewMenu();

//创建链表
StudentNode *creatList(void);

//插入成绩
int insertStudentNode(StudentNode *aHead);

//查询成绩
int printList(StudentNode *aHead);

//修改成绩
int findAndEdit(StudentNode *aHead);

//删除成绩
int deleteRecordFromList(StudentNode *aHead);

//打印成绩
void printRecordList();

#endif // SCOREMANAGE_H_INCLUDED
