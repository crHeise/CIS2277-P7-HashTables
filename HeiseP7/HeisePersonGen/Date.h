/*
 * Programmer: Chris Heise
 * Email: cheise3@cnm.edu
 * Course: CIS 2277-R01
 * Program: P1 The Person Class
 */

 //File: Date.h

#ifndef _DATE_H
#define _DATE_H

#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

class Date
{
private:
	int month{ 1 }, day{ 1 }, year{ 1970 };
	string description;
	year_month_day ymd;

public:
	Date();
	Date(int m, int d, int y, string desc);
	void SetDate(int m, int d, int y, string desc);
	void SetDesc(string d) { description = d; }

	string GetFormattedDate();

	int GetYear() { return year; }
	int GetMonth() { return month; }
	int GetDay() { return day; }
	year_month_day GetYearMonthDay() const { return ymd; }
};

#endif