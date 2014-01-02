#include <ctype.h>
#include "InvertedIndex.h"
#include "JR_Color.h"

//元素位置类
Location::Location(int aRow, int aCol, int aLength, Location *aNext)
{
	m_row = aRow;
	m_col = aCol;
	m_length = aLength;
	m_next = aNext;
}
Location::~Location()
{
	//if( m_next )
	//{
	//	delete m_next; //bug
	//}
	//cout << "delete" << endl;

	delete m_next;
}
void Location::setRow(int aRow)
{
	m_row = aRow;
}
void Location::setCol(int aCol)
{
	m_col = aCol;
}
void Location::setLength(int aLength)
{
	m_length = aLength;
}
void Location::setNext(Location * aNext)
{
	m_next = aNext;
}
int Location::getRow() const
{
	return m_row;
}
int Location::getCol() const
{
	return m_col;
}
int Location::getLength() const
{
	return m_length;
}
Location * Location::getNext() const
{
	return m_next;
}
void Location::display() const
{
	if( m_next )				//递归输出locationList，所以看到的也是倒叙位置列表
	{
		m_next ->display();
	}

	cout << '(' << m_row << ',' << m_col << ',' << m_length << ") ";
}



//搜索键值类(索引表元素)
Seed::Seed(char * aKey, int aFrequency, Location * aLocation, Seed * aNext)
{
	m_key = new char[strlen(aKey)+1];
	strcpy(m_key,aKey);

	m_frequency = aFrequency;

	m_locationList = aLocation;
	
	m_next = aNext;
}
Seed::~Seed()
{	
	//if( m_next )
	//{
	//	delete m_next;  //bug
	//}

	delete []m_key;
	delete m_locationList;
}
void Seed::setKey(char * aKey)
{	
	m_key = new char[strlen(aKey) + 1];
	strcpy(m_key,aKey);
}
void Seed::setFrequency(int aFrequency)
{
	m_frequency = aFrequency;
}
void Seed::setLocationList(Location * aLocationList)
{
	m_locationList = aLocationList;
}
void Seed::setNext(Seed * aNext)
{
	m_next = aNext;
}
char * Seed::getKey() const
{
	return m_key;
}
int Seed::getFrequency() const
{
	return m_frequency;
}
Location * Seed::getLocationList() const
{
	return m_locationList;
}
Seed * Seed::getNext() const
{
	return m_next;
}
void Seed::display() const
{
	if( m_next )   //递归调用显示seed列表，所以看到的seelists为倒叙显示的
	{
		m_next ->display();   
	}

	cout << m_key << ' '; //key值

	cout << m_frequency << "times ";

	m_locationList ->display(); //key值所在位置的列表(也会递归)
	
	cout << endl;
}

//段落链表
Section::Section(int aMark, char * aContent, Section * aNext)
{
	m_mark = aMark;
	
	m_content = new char[strlen(aContent) + 1];
	strcpy(m_content,aContent);

	m_next = aNext;
}
Section::~Section()
{
	if( m_next )
	{
		m_next;  
	}

	delete m_next;
}
void Section::setMark(int aMark)
{
	m_mark = aMark;
}
void Section::setContent(char * aContent)
{
	m_content = new char[strlen(aContent) + 1];
	strcpy(m_content,aContent);
}
void Section::setNext(Section * aNext)
{
	m_next = aNext;
}
int Section::getMark() const
{
	return m_mark;
}
char * Section::getContent() const
{
	return m_content;
}
Section * Section::getNext() const
{
	return m_next;
}
void Section::display() const
{
	if( m_next )
	{
		m_next ->display();
	}
	cout << m_mark << ":" << m_content << endl;
}

//短文爬虫类
essayReptiles::essayReptiles(char * aDate, char * aTitle, char * anEssay)
{
	m_date = new char[strlen(aDate)+1];
	strcpy(m_date,aDate);

	m_title = new char[strlen(aTitle)+1];
	strcpy(m_title,aTitle);

	m_essay = new char[strlen(anEssay)+1];
	strcpy(m_essay,anEssay);

	m_unique = NULL;

	m_sectionList = NULL;
	m_sectionSize = 0; //我的段数
	m_seedList = NULL;
	m_seedSize = 0;	//键值个数

	int wordIndex = 0;
	int wordCount = 0;     //整篇短文当前单词位置
	int tempWordCount = 0; // 单词的首字母位置 ，值由 wordCount 来  
	int sectionWordCount = 0; //当前段的单词的位置

	int sectionCount = 0;  //段落计数
	char * tempWord = NULL;
	Seed ** seed_p = &m_seedList;
	Seed * temp_seed_p = NULL;
	Location *location_p = NULL;

	Seed * temp_seed = NULL;
	Location * temp_location = NULL;

	char * tempSection = NULL;
	Section * temp_section_p = m_sectionList; //段列表，不需要每次遍历是否已有重复段

	//频数记录
	Seed * m_frequency_temp = NULL;
	int frequencyFlag = 0;

	for(int i = 0; i < strlen(m_essay); i++, sectionWordCount++)   //扫描全文，一次遍历爬出所有东西
	{	
		//扫描到一个词
		//if( m_essay[i] == ' ' || m_essay[i] == ',' || m_essay[i] == '.' || m_essay[i] == '\\' || m_essay[i] == '(' || m_essay[i] == ')' )
		if( !isalpha(m_essay[i]) ) 
		{	
			tempWordCount = wordCount;  //存储当前单词的首字母位置
			tempWord = new char[i - tempWordCount + 1];  //存储拼接单词

			for(wordIndex = 0; wordIndex < (i - tempWordCount); wordIndex++)  //写入tempWord单词
			{
				tempWord[wordIndex] = m_essay[wordCount++];
			}
			tempWord[wordIndex] = '\0';

			//cout << tempWord << endl;
			
			//此时 wordCount == i 下步 wordCount 指向下个单词的首字母
			wordCount = i + 1;

			temp_location = new Location(sectionCount,sectionWordCount - ( i - tempWordCount),i - tempWordCount,NULL);//存储当前单词的位置
			temp_seed = new Seed(tempWord,1,temp_location,NULL);

			/*cout << temp_location ->getRow() << endl;
			cout << temp_location ->getCol() << endl;*/

			/*cout << temp_seed ->getKey() << endl;
			cout << temp_seed ->getLocationList() << endl;
			cout << temp_seed ->getNext() << endl;*/

			//扫描已有键值链表
			temp_seed_p = m_seedList;
			while( temp_seed_p && (strcmp(temp_seed_p ->getKey(),tempWord)) && (temp_seed_p ->getNext()) )  //找到当前值是否已有位置列表
			{
				temp_seed_p = temp_seed_p ->getNext();
			}
			seed_p = &temp_seed_p;
			
			if( !(*seed_p) ) //当第一次temp_seed == NULL时
			{
				m_seedList = temp_seed;  // 把当前键值的地址交给seedList
				m_seedSize++;         //键值++
			}
			else if( !(strcmp((*seed_p) ->getKey(),tempWord)) )  //查到关键值
			{	
				(*seed_p) ->setFrequency((*seed_p) ->getFrequency() + 1);  //seed频数加一

				if( (*seed_p) ->getFrequency() > frequencyFlag )  //如果当前键值频数大于 frequencyFlag
				{
					frequencyFlag = (*seed_p) ->getFrequency();  //更新 frequencyFlag
					
					//更新键值
					delete []m_unique;
					m_unique = new char[strlen((*seed_p) ->getKey()) + 1]; 
					strcpy(m_unique,(*seed_p) ->getKey());
				}
				
				location_p = (*seed_p) ->getLocationList();

				while( location_p ->getNext() )    //找到该键值位置列表的最后个位置
				{
					location_p = location_p ->getNext();
				}
				location_p ->setNext(temp_location);
			}
			else		//当无该键值的记录时
			{
				(*seed_p) ->setNext(temp_seed);         //在键值列表最后添加新键值
				m_seedSize++;                 //键值++
			}
		}

		//扫描到一句   //一个弱智的判断
		if( m_essay[i] == '.' || m_essay[i] == '!' || m_essay[i] == ';' || m_essay[i] == '?' )   
		{
			tempSection = new char[sectionWordCount + 2];

			for(wordIndex = 0; wordIndex < sectionWordCount + 1; wordIndex++)
			{
				tempSection[wordIndex] = m_essay[i - sectionWordCount + wordIndex];
			}
			//tempSection[wordIndex] = m_essay[i];
			tempSection[wordIndex+1] = '\0';

			if( !temp_section_p )   //第一段
			{
				m_sectionList = new Section(sectionCount,tempSection,NULL);
				temp_section_p = m_sectionList;
			}
			else
			{
				temp_section_p ->setNext(new Section(sectionCount,tempSection,NULL));
				temp_section_p = temp_section_p ->getNext();
			}

			m_sectionSize++;
			sectionWordCount = 0;   //段落字符计数器归零
			sectionCount++;        //段落数加一
			i++;
		}
	}	
}
essayReptiles::~essayReptiles()
{
	//短文信息
	delete m_date;  //我的时间
	delete m_title;  //我的标题
	delete m_essay;  //我的内容
	delete m_unique; //我的特有(频数最高的值)

	//段落列表
	delete m_sectionList;

	//键值列表
	delete m_seedList; //键值个数
}
void essayReptiles::setDate( char *aDate)
{
	m_date = aDate;
}
void essayReptiles::setTitle( char *aTitle)
{
	m_title = aTitle;
}
void essayReptiles::setEssay( char *anEssay)
{
	m_essay = anEssay;
}
char * essayReptiles::getDate() const
{
	return m_date;
}
char * essayReptiles::getTitle() const
{
	return m_title;
}
char * essayReptiles::getEssay() const
{
	return m_essay;
}
char * essayReptiles::getUnique() const
{
	return m_unique;
}
Section * essayReptiles::getSectionLists() const
{
	return m_sectionList;
}
int essayReptiles::getSectionSize() const
{
	return m_sectionSize;
}
Seed * essayReptiles::getSeedLists() const
{
	return m_seedList;
}
int essayReptiles::getSeedSize() const
{
	return m_seedSize;
}
void essayReptiles::displayDate() const
{
	cout << "=================================================" << endl;
	cout << "Date:";
	cout << ' ' << m_date << ' ' << endl;
}
void essayReptiles::displayTitle() const
{
	cout << "=================================================" << endl;
	cout << "Title:";
	cout << ' ' << m_title << ' ' << endl;
}
void essayReptiles::displayEssay() const
{
	cout << "=================================================" << endl;
	cout << "Detail:" << endl;
	cout << m_essay << endl;
}
void essayReptiles::displayUnique() const
{
	cout << "=================================================" << endl;
	cout << "My unique: " << endl;
	cout << m_unique << endl;
}
void essayReptiles::displaySectionLists() const
{	
	cout << "=================================================" << endl;
	cout << "In section detail:" << endl;
	m_sectionList ->display();
}
void essayReptiles::displaySeedLists() const
{	
	cout << "=================================================" << endl;
	cout << "In keywords detail: ";
	cout << " +This text have " << m_seedSize << " keywords+" << endl; 
	
	m_seedList ->display();
}

bool essayReptiles::Search(char * aStr) const
{

	cout << "=================================================" << endl;
	char * search_key = new char[strlen(aStr) + 1];
	strcpy(search_key,aStr);

	Seed * temp_seed_p = m_seedList;
	Location * temp_location_p = NULL;

	Section * temp_section_p = m_sectionList;

	char * temp_conten_p = NULL;

	while( temp_seed_p && strcmp(temp_seed_p ->getKey(),search_key) && temp_seed_p ->getNext() )
	{
		temp_seed_p = temp_seed_p ->getNext();
	}

	if( !strcmp(temp_seed_p ->getKey(),search_key) )   //找到该键值
	{	
		cout << "Find it! ^_^" << endl;
		cout << "< " << temp_seed_p ->getKey() << " >" << " appears " << temp_seed_p ->getFrequency() << " times in this text!" << endl;
		cout << "Hey! Here: " << endl;
		
		temp_location_p = temp_seed_p ->getLocationList();  //获得当前键值的位置链表

		while( temp_location_p )   //依次遍历该键值的位置链表
		{
			 //当该键值的位置在同段中有多个位置出现时,
			if( temp_location_p ->getNext() && temp_location_p ->getRow() == temp_location_p ->getNext() ->getRow() )  
			{
				cout << '(' << temp_location_p ->getRow() << ',' << temp_location_p ->getCol() << ") ";
				temp_location_p = temp_location_p ->getNext();

				continue;
			}

			temp_section_p = m_sectionList;
			while( temp_section_p )   //依次遍历该段列表
			{
				if( temp_section_p ->getMark() == temp_location_p ->getRow() )   //当该段的 mark ==  该键值的所在的段时
				{
					cout << '(' << temp_location_p ->getRow() << ',' << temp_location_p ->getCol() << ") ";

					//to do something here to let you keywords change background in this section!
					temp_conten_p = new char[strlen(temp_section_p ->getContent()) + 1];
					strcpy(temp_conten_p,temp_section_p ->getContent());

					for(int iCol = 0; temp_conten_p[iCol] != '\0'; iCol++)  //遍历该段内容
					{
						if( iCol == temp_location_p ->getCol() )  //当该段走到该键值的位置时
						{	
							JR_SetColor(12,10);   //change your words color!  //
							for(int iLocation = 0; iLocation < temp_location_p ->getLength(); iLocation++, iCol++)  //输出该单词
							{
								cout << temp_section_p ->getContent()[iCol];
							}
						}

						JR_SetColor(7,0);
						cout << temp_section_p ->getContent()[iCol];  //该段的非关键字部分
					}

					cout << endl;
				}

				temp_section_p = temp_section_p ->getNext();
			}

			temp_location_p = temp_location_p ->getNext();
		}
		cout << endl;

		return true;  
	}  //存在

	cout << "Sorry! I can't find it! -_-|||" << endl;
	return false;
}


