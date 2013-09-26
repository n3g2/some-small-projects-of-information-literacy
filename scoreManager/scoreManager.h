#ifndef SCOREMANAGE_H_INCLUDED
#define SCOREMANAGE_H_INCLUDED

typedef struct swapSub
{
	char subName[20];
}swapSub;

typedef struct SubjectNode
{
	char subName[20];
    int subScore;
}SubjectNode;

typedef struct StudentNode
{
    int ID;
    char stuName[20];
    SubjectNode *subLists;
    struct StudentNode *next;
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