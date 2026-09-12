#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:
	clsDate()
	{
		time_t t = time(0);
		tm *now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{
		vector<string> vDate = clsString::split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year)
	{
		clsDate Date1 = getDateFromDayOrderInYear(DateOrderInYear, Year);

		_Day = Date1.getDay();
		_Month = Date1.getMonth();
		_Year = Date1.getYear();
	}

	void setDay(short Day)
	{
		_Day = Day;
	}

	short getDay()
	{
		return _Day;
	}

	void setMonth(short Month)
	{
		_Month = Month;
	}

	short getMonth()
	{
		return _Month;
	}

	void setYear(short Year)
	{
		_Year = Year;
	}

	short getYear()
	{
		return _Year;
	}

	void print()
	{
		cout << dateToString() << endl;
	}

	static clsDate getSystemDate()
	{
		time_t t = time(0);
		tm *now = localtime(&t);

		short Year = now->tm_year + 1900;
		short Month = now->tm_mon + 1;
		short Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	static bool isValidDate(clsDate Date)
	{
		if (Date.getDay() < 1 || Date.getDay() > 31)
			return false;

		if (Date.getMonth() < 1 || Date.getMonth() > 12)
			return false;

		if (Date.getMonth() == 2)
		{
			if (isLeapYear(Date.getYear()))
			{
				if (Date.getDay() > 29)
					return false;
			}
			else
			{
				if (Date.getDay() > 28)
					return false;
			}
		}

		short DaysInMonth =
			numberOfDaysInAMonth(Date.getMonth(), Date.getYear());

		if (Date.getDay() > DaysInMonth)
			return false;

		return true;
	}

	bool isValid()
	{
		return isValidDate(*this);
	}

	static string dateToString(clsDate Date)
	{
		return to_string(Date.getDay()) + "/" +
			   to_string(Date.getMonth()) + "/" +
			   to_string(Date.getYear());
	}

	string dateToString()
	{
		return dateToString(*this);
	}

	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) ||
			   (Year % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static short numberOfDaysInAYear(short Year)
	{
		return isLeapYear(Year) ? 366 : 365;
	}

	short numberOfDaysInAYear()
	{
		return numberOfDaysInAYear(_Year);
	}

	static int numberOfHoursInAYear(short Year)
	{
		return numberOfDaysInAYear(Year) * 24;
	}

	int numberOfHoursInAYear()
	{
		return numberOfHoursInAYear(_Year);
	}

	static int numberOfMinutesInAYear(short Year)
	{
		return numberOfHoursInAYear(Year) * 60;
	}

	int numberOfMinutesInAYear()
	{
		return numberOfMinutesInAYear(_Year);
	}

	static int numberOfSecondsInAYear(short Year)
	{
		return numberOfMinutesInAYear(Year) * 60;
	}

	int numberOfSecondsInAYear()
	{
		return numberOfSecondsInAYear(_Year);
	}

	static short numberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;

		int Days[12] =
			{
				31, 28, 31, 30, 31, 30,
				31, 31, 30, 31, 30, 31};

		return (Month == 2)
				   ? (isLeapYear(Year) ? 29 : 28)
				   : Days[Month - 1];
	}

	short numberOfDaysInAMonth()
	{
		return numberOfDaysInAMonth(_Month, _Year);
	}

	static short numberOfHoursInAMonth(short Month, short Year)
	{
		return numberOfDaysInAMonth(Month, Year) * 24;
	}

	short numberOfHoursInAMonth()
	{
		return numberOfHoursInAMonth(_Month, _Year);
	}

	static int numberOfMinutesInAMonth(short Month, short Year)
	{
		return numberOfHoursInAMonth(Month, Year) * 60;
	}

	int numberOfMinutesInAMonth()
	{
		return numberOfMinutesInAMonth(_Month, _Year);
	}

	static int numberOfSecondsInAMonth(short Month, short Year)
	{
		return numberOfMinutesInAMonth(Month, Year) * 60;
	}

	int numberOfSecondsInAMonth()
	{
		return numberOfSecondsInAMonth(_Month, _Year);
	}

	static short dayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) +
				(y / 400) + ((31 * m) / 12)) %
			   7;
	}

	short dayOfWeekOrder()
	{
		return dayOfWeekOrder(_Day, _Month, _Year);
	}

	static string dayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] =
			{
				"Sun", "Mon", "Tue", "Wed",
				"Thu", "Fri", "Sat"};

		return arrDayNames[DayOfWeekOrder];
	}

	static string dayShortName(short Day, short Month, short Year)
	{
		string arrDayNames[] =
			{
				"Sun", "Mon", "Tue", "Wed",
				"Thu", "Fri", "Sat"};

		return arrDayNames[dayOfWeekOrder(Day, Month, Year)];
	}

	string dayShortName()
	{
		string arrDayNames[] =
			{
				"Sun", "Mon", "Tue", "Wed",
				"Thu", "Fri", "Sat"};

		return arrDayNames[dayOfWeekOrder(_Day, _Month, _Year)];
	}

	static string monthShortName(short MonthNumber)
	{
		string Months[12] =
			{
				"Jan", "Feb", "Mar",
				"Apr", "May", "Jun",
				"Jul", "Aug", "Sep",
				"Oct", "Nov", "Dec"};

		return Months[MonthNumber - 1];
	}

	string monthShortName()
	{
		return monthShortName(_Month);
	}

	static void printMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;
		int current = dayOfWeekOrder(1, Month, Year);

		NumberOfDays = numberOfDaysInAMonth(Month, Year);

		printf("\n  _______________%s_______________\n\n",
			   monthShortName(Month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;

		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");
	}

	void printMonthCalendar()
	{
		printMonthCalendar(_Month, _Year);
	}

	static void printYearCalendar(int Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");

		for (int i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, Year);
		}
	}

	void printYearCalendar()
	{
		printYearCalendar(_Year);
	}

	static short daysFromTheBeginingOfTheYear(
		short Day,
		short Month,
		short Year)
	{
		short TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += numberOfDaysInAMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;
	}

	short daysFromTheBeginingOfTheYear()
	{
		return daysFromTheBeginingOfTheYear(
			_Day, _Month, _Year);
	}

	static clsDate getDateFromDayOrderInYear(
		short DateOrderInYear,
		short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date.setYear(Year);
		Date.setMonth(1);

		while (true)
		{
			MonthDays =
				numberOfDaysInAMonth(Date.getMonth(), Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.setMonth(Date.getMonth() + 1);
			}
			else
			{
				Date.setDay(RemainingDays);
				break;
			}
		}

		return Date;
	}

	void addDays(short Days)
	{
		short RemainingDays =
			Days + daysFromTheBeginingOfTheYear();

		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays =
				numberOfDaysInAMonth(_Month, _Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}
		}
	}

	static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.getYear() < Date2.getYear())
				   ? true
				   : (
						 Date1.getYear() == Date2.getYear()
							 ? (
								   Date1.getMonth() < Date2.getMonth()
									   ? true
									   : (
											 Date1.getMonth() == Date2.getMonth()
												 ? Date1.getDay() < Date2.getDay()
												 : false))
							 : false);
	}

	bool isDateBeforeDate2(clsDate Date2)
	{
		return isDate1BeforeDate2(*this, Date2);
	}

	static bool isDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return Date1.getYear() == Date2.getYear() &&
			   Date1.getMonth() == Date2.getMonth() &&
			   Date1.getDay() == Date2.getDay();
	}

	bool isDateEqualDate2(clsDate Date2)
	{
		return isDate1EqualDate2(*this, Date2);
	}

	static bool isLastDayInMonth(clsDate Date)
	{
		return Date.getDay() ==
			   numberOfDaysInAMonth(
				   Date.getMonth(),
				   Date.getYear());
	}

	bool isLastDayInMonth()
	{
		return isLastDayInMonth(*this);
	}

	static bool isLastMonthInYear(short Month)
	{
		return Month == 12;
	}

	static clsDate addOneDay(clsDate Date)
	{
		if (isLastDayInMonth(Date))
		{
			if (isLastMonthInYear(Date.getMonth()))
			{
				Date.setMonth(1);
				Date.setDay(1);
				Date.setYear(Date.getYear() + 1);
			}
			else
			{
				Date.setDay(1);
				Date.setMonth(Date.getMonth() + 1);
			}
		}
		else
		{
			Date.setDay(Date.getDay() + 1);
		}

		return Date;
	}

	void addOneDay()
	{
		*this = addOneDay(*this);
	}

	static void swapDates(clsDate &Date1, clsDate &Date2)
	{
		clsDate TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static int getDifferenceInDays(
		clsDate Date1,
		clsDate Date2,
		bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!isDate1BeforeDate2(Date1, Date2))
		{
			swapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (isDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = addOneDay(Date1);
		}

		return IncludeEndDay
				   ? ++Days * SwapFlagValue
				   : Days * SwapFlagValue;
	}

	int getDifferenceInDays(
		clsDate Date2,
		bool IncludeEndDay = false)
	{
		return getDifferenceInDays(
			*this, Date2, IncludeEndDay);
	}

	static int calculateMyAgeInDays(clsDate DateOfBirth)
	{
		return getDifferenceInDays(
			DateOfBirth,
			clsDate::getSystemDate(),
			true);
	}

	static clsDate increaseDateByOneWeek(clsDate &Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = addOneDay(Date);
		}

		return Date;
	}

	void increaseDateByOneWeek()
	{
		increaseDateByOneWeek(*this);
	}

	static clsDate increaseDateByXWeeks(
		short Weeks,
		clsDate &Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = increaseDateByOneWeek(Date);
		}

		return Date;
	}

	void increaseDateByXWeeks(short Weeks)
	{
		increaseDateByXWeeks(Weeks, *this);
	}

	static clsDate increaseDateByOneMonth(clsDate &Date)
	{
		if (Date.getMonth() == 12)
		{
			Date.setMonth(1);
			Date.setYear(Date.getYear() + 1);
		}
		else
		{
			Date.setMonth(Date.getMonth() + 1);
		}

		short NumberOfDaysInCurrentMonth =
			numberOfDaysInAMonth(
				Date.getMonth(),
				Date.getYear());

		if (Date.getDay() > NumberOfDaysInCurrentMonth)
		{
			Date.setDay(NumberOfDaysInCurrentMonth);
		}

		return Date;
	}

	void increaseDateByOneMonth()
	{
		increaseDateByOneMonth(*this);
	}

	static clsDate increaseDateByXDays(
		short Days,
		clsDate &Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = addOneDay(Date);
		}

		return Date;
	}

	void increaseDateByXDays(short Days)
	{
		increaseDateByXDays(Days, *this);
	}

	static clsDate increaseDateByXMonths(
		short Months,
		clsDate &Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = increaseDateByOneMonth(Date);
		}

		return Date;
	}

	void increaseDateByXMonths(short Months)
	{
		increaseDateByXMonths(Months, *this);
	}

	static clsDate increaseDateByOneYear(clsDate &Date)
	{
		Date.setYear(Date.getYear() + 1);
		return Date;
	}

	void increaseDateByOneYear()
	{
		increaseDateByOneYear(*this);
	}

	static clsDate increaseDateByXYears(
		short Years,
		clsDate &Date)
	{
		Date.setYear(Date.getYear() + Years);
		return Date;
	}

	void increaseDateByXYears(short Years)
	{
		increaseDateByXYears(Years, *this);
	}

	static clsDate increaseDateByOneDecade(clsDate &Date)
	{
		Date.setYear(Date.getYear() + 10);
		return Date;
	}

	void increaseDateByOneDecade()
	{
		increaseDateByOneDecade(*this);
	}

	static clsDate increaseDateByXDecades(
		short Decades,
		clsDate &Date)
	{
		Date.setYear(Date.getYear() + Decades * 10);
		return Date;
	}

	void increaseDateByXDecades(short Decades)
	{
		increaseDateByXDecades(Decades, *this);
	}

	static clsDate increaseDateByOneCentury(clsDate &Date)
	{
		Date.setYear(Date.getYear() + 100);
		return Date;
	}

	void increaseDateByOneCentury()
	{
		increaseDateByOneCentury(*this);
	}

	static clsDate increaseDateByOneMillennium(clsDate &Date)
	{
		Date.setYear(Date.getYear() + 1000);
		return Date;
	}

	void increaseDateByOneMillennium()
	{
		increaseDateByOneMillennium(*this);
	}

	static clsDate decreaseDateByOneDay(clsDate Date)
	{
		if (Date.getDay() == 1)
		{
			if (Date.getMonth() == 1)
			{
				Date.setMonth(12);
				Date.setDay(31);
				Date.setYear(Date.getYear() - 1);
			}
			else
			{
				Date.setMonth(Date.getMonth() - 1);
				Date.setDay(
					numberOfDaysInAMonth(
						Date.getMonth(),
						Date.getYear()));
			}
		}
		else
		{
			Date.setDay(Date.getDay() - 1);
		}

		return Date;
	}

	void decreaseDateByOneDay()
	{
		*this = decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByOneWeek(clsDate &Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = decreaseDateByOneDay(Date);
		}

		return Date;
	}

	void decreaseDateByOneWeek()
	{
		decreaseDateByOneWeek(*this);
	}

	static clsDate decreaseDateByXWeeks(
		short Weeks,
		clsDate &Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = decreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void decreaseDateByXWeeks(short Weeks)
	{
		decreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate decreaseDateByOneMonth(clsDate &Date)
	{
		if (Date.getMonth() == 1)
		{
			Date.setMonth(12);
			Date.setYear(Date.getYear() - 1);
		}
		else
		{
			Date.setMonth(Date.getMonth() - 1);
		}

		short NumberOfDaysInCurrentMonth =
			numberOfDaysInAMonth(
				Date.getMonth(),
				Date.getYear());

		if (Date.getDay() > NumberOfDaysInCurrentMonth)
		{
			Date.setDay(NumberOfDaysInCurrentMonth);
		}

		return Date;
	}

	void decreaseDateByOneMonth()
	{
		decreaseDateByOneMonth(*this);
	}

	static clsDate decreaseDateByXDays(
		short Days,
		clsDate &Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = decreaseDateByOneDay(Date);
		}

		return Date;
	}

	void decreaseDateByXDays(short Days)
	{
		decreaseDateByXDays(Days, *this);
	}

	static clsDate decreaseDateByXMonths(
		short Months,
		clsDate &Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = decreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void decreaseDateByXMonths(short Months)
	{
		decreaseDateByXMonths(Months, *this);
	}

	static clsDate decreaseDateByOneYear(clsDate &Date)
	{
		Date.setYear(Date.getYear() - 1);
		return Date;
	}

	void decreaseDateByOneYear()
	{
		decreaseDateByOneYear(*this);
	}

	static clsDate decreaseDateByXYears(
		short Years,
		clsDate &Date)
	{
		Date.setYear(Date.getYear() - Years);
		return Date;
	}

	void decreaseDateByXYears(short Years)
	{
		decreaseDateByXYears(Years, *this);
	}

	static clsDate decreaseDateByOneDecade(clsDate &Date)
	{
		Date.setYear(Date.getYear() - 10);
		return Date;
	}

	void decreaseDateByOneDecade()
	{
		decreaseDateByOneDecade(*this);
	}

	static clsDate decreaseDateByXDecades(
		short Decades,
		clsDate &Date)
	{
		Date.setYear(Date.getYear() - Decades * 10);
		return Date;
	}

	void decreaseDateByXDecades(short Decades)
	{
		decreaseDateByXDecades(Decades, *this);
	}

	static clsDate decreaseDateByOneCentury(clsDate &Date)
	{
		Date.setYear(Date.getYear() - 100);
		return Date;
	}

	void decreaseDateByOneCentury()
	{
		decreaseDateByOneCentury(*this);
	}

	static clsDate decreaseDateByOneMillennium(clsDate &Date)
	{
		Date.setYear(Date.getYear() - 1000);
		return Date;
	}

	void decreaseDateByOneMillennium()
	{
		decreaseDateByOneMillennium(*this);
	}

	static bool isEndOfWeek(clsDate Date)
	{
		return dayOfWeekOrder(
				   Date.getDay(),
				   Date.getMonth(),
				   Date.getYear()) == 6;
	}

	bool isEndOfWeek()
	{
		return isEndOfWeek(*this);
	}

	static bool isWeekEnd(clsDate Date)
	{
		short DayIndex =
			dayOfWeekOrder(
				Date.getDay(),
				Date.getMonth(),
				Date.getYear());

		return DayIndex == 5 || DayIndex == 6;
	}

	bool isWeekEnd()
	{
		return isWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate Date)
	{
		return !isWeekEnd(Date);
	}

	bool isBusinessDay()
	{
		return isBusinessDay(*this);
	}

	static short daysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - dayOfWeekOrder(
					   Date.getDay(),
					   Date.getMonth(),
					   Date.getYear());
	}

	short daysUntilTheEndOfWeek()
	{
		return daysUntilTheEndOfWeek(*this);
	}

	static short daysUntilTheEndOfMonth(clsDate Date1)
	{
		clsDate EndOfMonthDate;

		EndOfMonthDate.setDay(
			numberOfDaysInAMonth(
				Date1.getMonth(),
				Date1.getYear()));

		EndOfMonthDate.setMonth(Date1.getMonth());
		EndOfMonthDate.setYear(Date1.getYear());

		return getDifferenceInDays(
			Date1,
			EndOfMonthDate,
			true);
	}

	short daysUntilTheEndOfMonth()
	{
		return daysUntilTheEndOfMonth(*this);
	}

	static short daysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;

		EndOfYearDate.setDay(31);
		EndOfYearDate.setMonth(12);
		EndOfYearDate.setYear(Date1.getYear());

		return getDifferenceInDays(
			Date1,
			EndOfYearDate,
			true);
	}

	short daysUntilTheEndOfYear()
	{
		return daysUntilTheEndOfYear(*this);
	}

	static short calculateBusinessDays(
		clsDate DateFrom,
		clsDate DateTo)
	{
		short Days = 0;

		while (isDate1BeforeDate2(DateFrom, DateTo))
		{
			if (isBusinessDay(DateFrom))
				Days++;

			DateFrom = addOneDay(DateFrom);
		}

		return Days;
	}

	static short calculateVacationDays(
		clsDate DateFrom,
		clsDate DateTo)
	{
		return calculateBusinessDays(DateFrom, DateTo);
	}

	static clsDate calculateVacationReturnDate(
		clsDate DateFrom,
		short VacationDays)
	{
		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{
			if (isWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = addOneDay(DateFrom);
		}

		for (short i = 1; i <= WeekEndCounter; i++)
		{
			DateFrom = addOneDay(DateFrom);
		}

		return DateFrom;
	}

	static bool isDate1AfterDate2(
		clsDate Date1,
		clsDate Date2)
	{
		return !isDate1BeforeDate2(Date1, Date2) &&
			   !isDate1EqualDate2(Date1, Date2);
	}

	bool isDateAfterDate2(clsDate Date2)
	{
		return isDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare
	{
		Before = -1,
		Equal = 0,
		After = 1
	};

	static enDateCompare compareDates(
		clsDate Date1,
		clsDate Date2)
	{
		if (isDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (isDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	enDateCompare compareDates(clsDate Date2)
	{
		return compareDates(*this, Date2);
	}

	static string getSystemDateTimeString()
	{
		// system datetime string
		time_t t = time(0);
		tm *now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
	}
};