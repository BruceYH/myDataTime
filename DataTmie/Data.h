#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <cstdio>

using namespace std;

namespace DATA
{
	class Data
	{
	public:
		Data(const char* date);  //xxxx.xx.xx
		Data(int y = 1900, int m = 1, int d = 1);		
		void setYear(int y);
		void setMonth(int m);
		void setDay(int d);
		void printData()const;
		void addDay();
		void subDay();

		static bool isLeap(int year);
		static Data daysToDate(int totalDays);
		static void stringToInt(const char* str, int& y, int& m, int& d);
		int daysYear(int year);						//ĳ���������
		int daysOfyear();							//�Ǳ���������������
		int daysCntTotal(int y = 1900, int m = 1, int d = 1);

	private:
		void updateMonNumFeb();
		bool isInvalidDate(int y, int m, int d);
		
	private:
		int year;
		int month;
		int day;
		static int monNum[13];

	public:
		friend ostream& operator<<(ostream& out, const Data& data);

		Data operator+=(int d);	//���϶����죬�ı��ʼ���ڵ�ֵ
		Data operator-=(int d);	//��ȥ�����죬�ı��ʼ���ڵ�ֵ

		Data operator++();		//data++
		Data operator++(int);	//++data

		Data operator--();		//data--
		Data operator--(int);	//--data

		int operator-(Data& data);	//�������������������
	};

}




#endif

