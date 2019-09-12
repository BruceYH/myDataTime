#ifndef DATA_TIME_H_
#define DATA_TIME_H_

#include "time.h"
#include "data.h"

using namespace DATA;
using namespace TIME;

namespace DATA_TIME
{
	class DataTime
	{
		Data data;
		Time* time;
	public:
		DataTime(const char* dataTimeStr);//xxxx.xx.xx xx:xx:xx
		DataTime(Data valData, Time valTime);
		DataTime(int y = 1900, int m = 1, int d = 1, int h = 0, int min = 0, int s = 0);
		~DataTime();
	public:
		void showDataTime();
		void addDataTime();
		void subDataTime();
		char* leftSartEndofCharacter(char* toStr, char endCh, const char* fromStr);
		char* SartOfCharacterToEnd(char* toStr, char endCh, const char* fromStr);
	};
}




#endif

