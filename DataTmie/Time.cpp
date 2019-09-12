#include "time.h"

namespace TIME
{
	Time::Time(int h, int min, int s)
	{
		if (!isInvalidTime(h, min, s))
		{
			hours = 0;
			minute = 0;
			second = 0;
			return;
		}
		hours = h;
		minute = min;
		second = s;

	}

	void Time::setHours(int h)
	{
		if (0 < h < 23)
		{
			return;   //数据不符合，则不修改原有数据
		}
		hours = h;

	}
	void Time::setMinute(int min)
	{
		if (0 < min < 59)
		{
			return;   //数据不符合，则不修改原有数据
		}
		minute = min;

	}
	void Time::setSecond(int s)
	{
		if (0 < s < 59)
		{
			return;   //数据不符合，则不修改原有数据
		}
		second = s;
	}
	void Time::printTime()const
	{
		char buff[10];
		sprintf_s(buff, "%02d:%02d:%02d", hours, minute, second);
		cout << buff << endl;
	}

	bool Time::isInvalidTime(int h, int min, int s)
	{
		if ((h < 0 || h >23) || (min < 0 || min>59) || (s < 0 || s>59))
		{
			return false;
		}
		return true;

	}


	//time++
	Time Time::operator++()
	{
		second++;
		if (second > 59)
		{
			second = 0;
			minute++;
			if (minute > 59)
			{
				minute = 0;
				hours++;
				if (hours > 23)
				{
					hours = 0;
				}
			}
		}

		return  *this;
	}

	//++time
	Time Time::operator++(int)
	{
		Time tmp = *this;

		second++;
		if (second > 59)
		{
			second = 0;
			minute++;
			if (minute > 59)
			{
				minute = 0;
				hours++;
				if (hours > 23)
				{
					hours = 0;
				}
			}
		}
		return tmp;
	}

	//time--
	Time Time::operator--()
	{
		second--;
		if (second < 0)
		{
			second =59;
			minute--;
			if (minute < 0)
			{
				minute = 59;
				hours--;
				if (hours < 0)
				{
					hours = 23;
				}
			}
		}

		return  *this;
	}

	//--time
	Time Time::operator--(int)
	{
		Time tmp = *this;

		second--;
		if (second < 0 )
		{
			second = 59;
			minute--;
			if (minute < 0)
			{
				minute = 59;
				hours--;
				if (hours < 0)
				{
					hours = 23;
				}
			}
		}
		return tmp;
	}

	bool Time::operator == (Time time)
	{
		if (hours == time.hours && minute == time.minute && second == time.second)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	ostream& operator<<(ostream& out, const Time& time)
	{
		char buf[12];

		sprintf_s(buf, "%02d:%02d:%02d", time.hours, time.minute, time.second);
		cout << buf << endl;

		return out;
	}


}