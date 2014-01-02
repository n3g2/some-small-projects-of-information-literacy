/*
* JR_Color.c (1.0)
* 字条界面颜色控制函数实现
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-6-1
*/

#include "JR_Color.h"
static int isInitColor = 0;
HANDLE Handle_Color;    //输出窗口句柄

void initColor(){
    if(isInitColor) return ;
    isInitColor = 1;
    Handle_Color = GetStdHandle(STD_OUTPUT_HANDLE);
}

/*
    0 = 黑色
    1 = 白色  //浅蓝色(测试纠正
    2 = 军绿色
    3 = 蓝绿色
    4 = 深红色
    5 = 紫色
    6 = 黄绿色
    7 = 灰色        //windows默认
    8 = 深灰色
    9 = 蓝色
    10 = 绿色
    11 = 亮蓝色
    12 = 红色
    13 = 粉紫色
    14 = 黄色
    15 = 米白色
*/
/* 设置输出颜色 */
void JR_SetColor(int textcolor, int bgcolor){
    int color = textcolor + bgcolor * 16;
    initColor();
    SetConsoleTextAttribute(Handle_Color, color);
}


