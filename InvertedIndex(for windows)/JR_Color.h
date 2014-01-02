/*
* JR_Color.h (1.0)
* 字条界面颜色控制函数定义
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-6-1
*/

#ifndef JR_COLOR_H
#define JR_COLOR_H

#include <windows.h>

#define BLACK           0   //黑色
#define WHITE           1   //白色?   //浅蓝色(测试纠正)
#define ARMY_GREEN      2   //军绿色
#define BLUE_GREEN      3   //蓝绿色
#define DEEP_RED        4   //深红色
#define PURPLE          5   //紫色
#define YELLOW_GREEN    6   //黄绿色
#define GREY            7   //灰色     //windows默认
#define DARK_GREY       8   //深灰色
#define BLUE            9   //蓝色
#define GREEN           10  //绿色
#define BRIGHT_BLUE     11  //亮蓝色
#define RED             12  //红色
#define LIGHT_PURPLE    13  //粉紫色
#define YELLOW          14  //黄色
#define OFF_WHITE       15  //米白色


/* 设置输出颜色 */
void JR_SetColor(int textcolor, int bgcolor);

#endif
