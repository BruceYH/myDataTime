#include "data.h"
#include "time.h"
#include "dataTime.h"
#include <Windows.h>

using namespace DATA;
using namespace TIME;
using namespace DATA_TIME;

void dataTest(void);
void timeTest(void);
void dataTimeTest(void);


int main(void)
{

//	dataTest();

//	timeTest();

	dataTimeTest();

	

	return 0;
}

void dataTest(void)
{
	Data a(2018, 3, 5);

	Data b(2008, 9, 10);

	cout << "日期a与b相差"<<a - b<<"天" << endl;

	while (1)
	{
		a.printData();
		a.addDay();
		a.printData();
		a.subDay();
		a.printData();

		a += 10;
		a.printData();

		a -= 10;
		a.printData();

		(a++).printData();
		(++a).printData();

		(a--).printData();
		(--a).printData();

		Sleep(2000);
		system("cls");
    }


}

void timeTest(void)
{
	Time time(23,00,04);

	while (1)
	{
		
//		time++;
//		time.printTime();

//		++time;
//		time.printTime();

//		time--;
//		time.printTime();

		--time;
		time.printTime();


	
		Sleep(1000);
		system("cls");
	}

}

void dataTimeTest(void)
{
	
	DataTime dataTime("2018.3.30 23:59:54");
	DataTime dataTime1("2018.3.30 00:00:05");

	while (1)
	{

		dataTime.addDataTime();
		dataTime.showDataTime();

		dataTime1.subDataTime();
		dataTime1.showDataTime();

		Sleep(1000);
		system("cls");
	}


}