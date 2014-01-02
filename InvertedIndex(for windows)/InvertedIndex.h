#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//元素位置
class Location
{
public:
	Location(int aRow = 0, int aCol = 0, int aLength = 0, Location *aNext = NULL);
	~Location();

	void setRow(int aRow);
	void setCol(int aCol);
	void setLength(int aLength);
	void setNext(Location * aNext);

	int getRow() const;
	int getCol() const;
	int getLength() const;
	Location * getNext() const;

	void display() const;
private:
	int m_row; //第几段
	int m_col; //第几个字
	int m_length; //长度
	Location *m_next;	//下个位置
};

//搜索键值类(索引表元素)
class Seed
{
public:
	Seed(char * aKey = "blcakpop", int aFrenqucy = 1, Location * aLocation = NULL, Seed * aNext = NULL);
	~Seed();

	void setKey(char * aKey);
	void setFrequency(int aFrequency);
	void setLocationList(Location * aLocationList);
	void setNext(Seed * aNext);

	char * getKey() const;
	int getFrequency() const;
	Location * getLocationList() const;
	Seed * getNext() const;

	void display() const;
private:
	char * m_key;
	int m_frequency;
	Location * m_locationList;
	Seed * m_next;
};

class Section
{
public:
	Section(int aMark = 0, char * aContent = "Hello!I'm Wang Ning!", Section * aNext = NULL);
	~Section();

	void setMark(int aMark);
	void setContent(char * aContent);
	void setNext(Section * aNext);

	int getMark() const;
	char * getContent() const;
	Section * getNext() const;

	void display() const;
private:
	int m_mark;
	char * m_content;
	Section * m_next;
};

//短文爬虫类
class essayReptiles
{
public:
	essayReptiles(char * aDate = "2014-1-1", char * aTitle = "Hello world", char * anEssay = "Hello world! ^_^");
	~essayReptiles();
	
	void setDate( char *aDate);
	void setTitle( char *aTitle);
	void setEssay( char *anEssay);
	
	char * getDate() const;
	char * getTitle() const;
	char * getEssay() const;
	char * getUnique() const;

	Section * getSectionLists() const;
	int getSectionSize() const;
	Seed * getSeedLists() const;
	int getSeedSize() const;

	void displayDate() const;
	void displayTitle() const;
	void displayEssay() const;  //显示全文
	void displayUnique() const;  //显示我的特有（频数最高的键值）
	void displaySectionLists() const; //显示分段后的短文
	void displaySeedLists() const;	//显示键值列表

	bool Search(char * aStr) const;
private:
	//短文信息
	char * m_date;  //我的时间
	char * m_title;  //我的标题
	char * m_essay;  //我的内容
	char * m_unique; //我的特有(频数最高的值)

	//短文分段数组
	Section * m_sectionList; //我的分段内容
	int m_sectionSize; //我的段数
	
	//键值列表2
	Seed * m_seedList; //键值列表首地址
	int m_seedSize;	//键值个数
};

#endif  // #ifndef INVERTEDINDEX_H
