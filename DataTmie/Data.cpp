#include "data.h"

using namespace DATA;

int Data::monNum[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

namespace DATA
{
	Data::Data(const char* date)
	{
		int y = 0;
		int m = 0;
		int d = 0;

		stringToInt(date, year, month, day);//日期字符串转换为整形数据

		if (!isInvalidDate(y, m, d))
		{
			year = 1900;
			month = 1;
			day = 1;
			return;
		}
		year = y;
		month = m;
		day = d;
	}

	Data::Data(int y, int m, int d)
	{
		if (!isInvalidDate(y, m, d))
		{
			year = 1900;
			month = 1;
			day = 1;
			return;
		}

		year = y;
		month = m;
		day = d;
	}

	bool Data::isInvalidDate(int year, int month, int day)
	{
		//数组： 输入的数据，在创建对象之前
		int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if ((year < 1) || (month < 0 || month>12) || (day<0 || day>mon[month]))
		{
			return false;
		}
		return true;
	}

	//将str字符串转换为对应的整型数据保存在y,m,d
	//"xxxx.xx.xx"    "xx:xx:xx"
	//  y   m   d
	void Data::stringToInt(const char* str, int& y, int& m, int& d)
	{
		y = 0; m = 0; d = 0;

		while (*str != '.' && *str != ':')
		{
			y = y * 10 + *str - '0';
			str++;

		}
		str++;
		while (*str != '.' && *str != ':')
		{
			m = m * 10 + *str - '0';
			str++;
		}
		str++;
		while (*str != '\0')
		{
			d = d * 10 + *str - '0';
			str++;
		}
	}

	void Data::setYear(int y)
	{
		if (y < 1918)
		{
			return;   //数据不符合，则不修改原有数据
		}
		year = y;
	}

	void Data::setMonth(int m)
	{
		if (m < 1 || m > 12)
		{
			return;
		}
		month = m;
	}

	void Data::setDay(int d)
	{
		updateMonNumFeb();
		if (d < 1 || d > monNum[month])
		{
			return;
		}
		day = d;
	}

	void Data::updateMonNumFeb()
	{
		if (isLeap(year))
		{
			monNum[2] = 29;
		}
		else
		{
			monNum[2] = 28;
		}
	}

	void Data::printData()const
	{
		char buf[12];
		sprintf_s(buf, "%d,%02d,%02d", year, month, day);
		cout << buf << endl;
	}

	bool Data::isLeap(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Data Data::daysToDate(int totalDays)
	{
		int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int y = 1900, m = 1, d = 1;

		while (totalDays > 365)
		{
			totalDays = totalDays - isLeap(y) - 365;
			y++;
		}

		if (isLeap(y))
		{
			mon[2] = 29;
		}
		while (totalDays > 0)
		{
			totalDays = totalDays - mon[m];
			if (totalDays < 0)
			{
				totalDays += mon[m];
				break;
			}
			else
			{
				m++;
			}
		}
		d = totalDays;

		return Data(y, m, d);

	}

	void Data::addDay()
	{
		day++;
		updateMonNumFeb();
		if (day > monNum[month])
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
	}

	void Data::subDay()
	{
		day--;
		updateMonNumFeb();
		if (day < 1)
		{
			month--;
			if (month < 1)
			{
				year--;
				if (year < 1900)
				{
					return;
				}
				month = 12;
			}
			day = monNum[month];
		}
	}
	
	ostream& operator<<(ostream& out, const Data& data)
	{
		char buf[12];
		sprintf_s(buf, "%d.%02d.%02d", data.year, data.month, data.day);
		cout << buf;
		return out;
	}


	Data Data::operator+=(int d)
	{

		int cnt = this->daysCntTotal() + d + 1;
		*this = daysToDate(cnt);
		return *this;
	}

	Data Data :: operator-=(int d)
	{
		//天数的统计会少一天
		int cnt = this->daysCntTotal() - d + 1;
		*this = daysToDate(cnt);
		return *this;
	}

	//++d
	Data Data::operator++()
	{
		day = day + 1;
		return *this;

		/**this += 1;
		return *this;*/
	}

	//d++
	Data Data::operator++(int)
	{
		Data ret = *this;
		day = day + 1;
		return ret;
	}

	//--d
	Data Data::operator--()
	{
		day = day - 1;
		return *this;
	}

	//d--
	Data Data::operator--(int)
	{
		Data ret = *this;
		day = day - 1;
		return ret;
	}

	//从某个日期开始统计到this日期所经过的总天数
	int  Data::daysCntTotal(int y, int m, int d)
	{
		if (!isInvalidDate(y, m, d))
		{
			return -1;
		}
		int cnt = 0;
		Data tmp(y, m, d);
		int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (y > year)
		{
			Data cmp = *this;
			*this = tmp;
			tmp = cmp;
		}

		if (y < year)
		{
			for (int i = y + 1; i < year; i++)
			{
				if (isLeap(i))
				{
					cnt += 366;
				}
				else
				{
					cnt += 365;
				}
			}
			cnt = cnt + this->daysOfyear() + daysYear(y) - tmp.daysOfyear();
		}
		else if (y == year)
		{
			cnt = daysYear(year) - tmp.daysOfyear();
		}

		return cnt;
	}

	//是本年所经过的天数
	int  Data::daysOfyear()
	{
		int cnt = 0;
		updateMonNumFeb();
		for (int i = 1; i < month; i++)
		{
			cnt += monNum[i];
		}
		cnt += day;

		return cnt;
	}

	//某年的总天数
	int  Data::daysYear(int year)
	{
		if (isLeap(year))
		{
			return 366;
		}
		return 365;
	}

	//两个日期相减相差多少天
	int Data::operator - (Data& data)
	{
		int cnt = this->daysCntTotal() - data.daysCntTotal();

		return cnt;
	}


}