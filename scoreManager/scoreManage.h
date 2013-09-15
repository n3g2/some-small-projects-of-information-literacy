#ifndef SCOREMANAGE_H_INCLUDED
#define SCOREMANAGE_H_INCLUDED

typedef struct SubjectNode
{
    char subName[20];
    int subScore;
    struct SubjectNode *next = NULL;
}SubjectNode;

typedef struct StudentNode
{
    int ID;
    char stuName[30];
    SubjectNode *subLists = NULL;
    struct StudentNode *next = NULL;
}StudentNode;

//显示菜单
char viewMenu();

//创建链表
StudentNode *creatList(void);

//插入成绩
int insertStudentNode(StudentNode *aHead);

//删除成绩
int deleteRecordFromList(StudentNode *aHead);

//修改成绩
int findAndEdit(StudentNode *aHead);

//查询成绩
int printList(StudentNode *aHead);

#endif // SCOREMANAGE_H_INCLUDED
