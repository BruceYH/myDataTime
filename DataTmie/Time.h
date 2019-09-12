#ifndef TIME_H_
#define TIME_H_

#include <iostream>

using namespace std;

namespace TIME
{
	class Time
	{
	public:
		Time(int h = 0, int min = 0, int s = 0);
		void setHours(int h);
		void setMinute(int min);
		void setSecond(int s);
		void printTime()const;

	private:
		bool isInvalidTime(int h, int min, int s);

	private:
		int hours;
		int minute;
		int second;

	public:
		Time operator++();		//time++
		Time operator++(int);	//++time

		Time operator--();		//time--
		Time operator--(int);	//--time

		bool operator==(Time time);
		friend ostream& operator<<(ostream& out, const Time& time);

	};

}

#endif

