#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InvertedIndex.h"
#include "JR_Color.h"

//测试用文档
//#define TEXT_COUNT 3
//static const char * const test_text[] =
//{
//	"Test cases for search engine is depends on the SRS(including business req.), web page layout (GUI) dependingon this we are writing test cases.\n"
//	"The above mention answer is the general overview for searchengine. If you are looking for any perticular conditionsmention it. \n"
//	, 
//	"Test1: Search functionality should not work when no keywordis entered and prompt to enter\n"
//	"Test2: List of links/paths should display matching at leastone of the keyword\n"
//	"Test3: Most suitable matches should display at the top ofthe list\n"
//	"Test4: Link should open in the same window.\n"
//	"Test5:Allow user to return to the search again by resettingor fresh \n"
//	, 
//	"1.To check whether when we give the websit it is correctly moved to that page\n"
//	"2.To check whether seach text box is there\n"
//	"3.To check whether when we give null value and click for search it must throw a error message\n"
//	"4.To check whether the user types any letter then it must display the related words\n"
//	"5.To check it must have a advanced search option\n"
//	"6.To check when we give search it must show the pages related to the what actually the user needs\n"
//	"7.To check whether it must work based upon seo \n"
//	"8.to check when it directs to search on the top it must display what the user enters to search\n"
//	, 
//	NULL
//};
//
//void PrintDocuments()
//{//打印文档
//	printf("PrintDocuments();\n");
//	const char * const * p = test_text;
//	int i=0;
//	while(*p){
//		printf("  %04d [%s]\n", i++, *p);
//		p++;
//	}
//	printf("\n");
//}

int main ( void )
{
	cout << "                 *************Welcome essay eptiles v0.1**************                            " << endl;
	essayReptiles anEssay("2014-1-1",
		"Testing text",
		"Test cases for search engine is depends on the SRS(including business req.), web page layout (GUI) dependingon this we are writing test cases."
		"The above mention answer is the general overview for searchengine. If you are looking for any perticular conditionsmention it."
		"Test1: Search functionality should not work when no keywordis entered and prompt to enter."
		"Test2: List of links/paths should display matching at leastone of the keyword."
		"Test3: Most suitable matches should display at the top ofthe list."
		"Test4: Link should open in the same window."
		"Test5:Allow user to return to the search again by resettingor fresh."
		"1:To check whether when we give the websit it is correctly moved to that page."
		"2:To check whether seach text box is there."
		"3:To check whether when we give null value and click for search it must throw a error message."
		"4:To check whether the user types any letter then it must display the related words. "
		"5:To check it must have a advanced search option."
		"6:To check when we give search it must show the pages related to the what actually the user needs."
		"7:To check whether it must work based upon seo."
	    "8:to check when it directs to search on the top it must display what the user enters to search."
		);

	essayReptiles *haha = new essayReptiles("2014-1-1","testing",
		"A fat man and a skinny man were arguing about who was the more polite. "
		"The skinny man said he was more polite because he always tipped his hat to ladies. "
		"But the fat man knew he was more courteous because, whenever he got up and offered his seat, two ladies could sit down. "
		);
	//anEssay.displayTitle();  //显示该篇短文的标题

	//anEssay.displayDate();   //显示该篇短文的日期

	//anEssay.displayEssay();  //显示该篇短文

	//anEssay.displayUnique(); //显示该篇短文的特殊键值（频数最高的）

	//anEssay.displaySectionLists();  //显示该篇短文的分段后的结果

	//anEssay.displaySeedLists();    //显示该篇短文的键值列表

	//anEssay.Search("the");        //搜索某值

	anEssay.Search("2");
	anEssay.Search("10");

	haha ->Search("polite");
	haha ->Search("courteous");

	delete haha;

	system("pause");
	return 0;
}
