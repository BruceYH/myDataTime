#include "dataTime.h"

namespace DATA_TIME
{
	char* DataTime::leftSartEndofCharacter(char* toStr, char endCh, const char* fromStr)
	{
		int i = 0;
		while (*fromStr != endCh)
		{
			toStr[i] = *fromStr;
			i++;
			fromStr++;
		}
		toStr[i] = 0;
		return toStr;
	}


	char* DataTime::SartOfCharacterToEnd(char* toStr, char endCh, const char* fromStr)
	{
		while (*fromStr != endCh)
		{
			fromStr++;
		}
		fromStr++;  //跳过endch字符

		int i = 0;
		while (*fromStr != '\0')
		{
			toStr[i] = *fromStr;
			i++;
			fromStr++;
		}
		toStr[i] = 0;
		return toStr;
	}


	//日期字符串 xxxx.xx.xx xx:xx:xx 
	DataTime::DataTime(const char* dataTimeStr)
	{
		int y = 0, m = 0, d = 0;      //年月日
		int h = 0, min = 0, s = 0;     //时分秒

		char dataStr[12] = { 0 };             //日期字符串
		char timeStr[12] = { 0 };             //时间字符串

		leftSartEndofCharacter(dataStr, 32, dataTimeStr);
		SartOfCharacterToEnd(timeStr, 32, dataTimeStr);
//		cout << dataStr << endl;
//		cout << timeStr << endl;
		Data::stringToInt(dataStr, y, m, d);
		Data::stringToInt(timeStr, h, min, s);

		data = Data(y, m, d);
		time = new Time(h, min, s);
	}


	DataTime::DataTime(Data valData,Time valTime)
	{
		data = valData;
		time = new Time(valTime);
	}


	DataTime::DataTime(int y, int m, int d, int h, int min, int s) :data(y, m, d)
	{
		time = new Time(h, min, s);
	}


	void DataTime::showDataTime()
	{
		cout << data << " " << *time << endl;
	}


	void DataTime::addDataTime()
	{
		(*time)++;
		if (*time ==Time(0, 0, 0))
		{
			data++;
			//data.addDay();
		}
	}


	void DataTime::subDataTime()
	{
		(*time)--;
		if (*time == Time(0, 0, 0))
		{
			data--;
			//data.subDay();
		}
	}

	DataTime::~DataTime()
	{
		delete time;
		time = NULL;
	}
	
}
