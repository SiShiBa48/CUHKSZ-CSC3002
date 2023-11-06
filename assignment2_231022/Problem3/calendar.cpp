/* P3:
 * File: calendar.cpp
 * ------------------
 * This file implements the p1calendar.h interface
 */

#include <string>
#include <iostream>
// #include "CSC3002OJActive/assignment2/lib.h" // for OJ test
// #include "CSC3002OJActive/assignment2/calendar.h" // for OJ test
#include "lib.h"      // For local test
#include "calendar.h" // For local test
using namespace std;

Month stringToMonth(string s)
{
   if (s == "JANUARY")
   {
      return JANUARY;
   }
   if (s == "FEBRUARY")
   {
      return FEBRUARY;
   }
   if (s == "MARCH")
   {
      return MARCH;
   }
   if (s == "APRIL")
   {
      return APRIL;
   }
   if (s == "MAY")
   {
      return MAY;
   }
   if (s == "JUNE")
   {
      return JUNE;
   }
   if (s == "JULY")
   {
      return JULY;
   }
   if (s == "AUGUST")
   {
      return AUGUST;
   }
   if (s == "SEPTEMBER")
   {
      return SEPTEMBER;
   }
   if (s == "OCTOBER")
   {
      return OCTOBER;
   }
   if (s == "NOVEMBER")
   {
      return NOVEMBER;
   }
   if (s == "DECEMBER")
   {
      return DECEMBER;
   }
}

/* TODO PART:
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
string monthToString(Month month)
{
   switch (month)
   {
   case (1):
      return "JANUARY";
      break;
   case (2):
      return "FEBRUARY";
      break;
   case (3):
      return "MARCH";
      break;
   case (4):
      return "APRIL";
      break;
   case (5):
      return "MAY";
      break;
   case (6):
      return "JUNE";
      break;
   case (7):
      return "JULY";
      break;
   case (8):
      return "AUGUST";
      break;
   case (9):
      return "SEPTEMBER";
      break;
   case (10):
      return "OCTOBER";
      break;
   case (11):
      return "NOVEMBER";
      break;
   case (12):
      return "DECEMBER";
      break;
   }
   return "";
}

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Date class.  The default
 * constructor creates a Date with a zero internal value that must
 * be assigned a new value before it is used.  The others initialize
 * the date from the arguments by calling the private initDate method.
 */

Date::Date()
{
   initDate(1, JANUARY, 1900);
}

Date::Date(int day, Month month, int year)
{
   initDate(day, month, year);
}

Date::Date(Month month, int day, int year)
{
   initDate(day, month, year);
}

/*
 * TODO function
 * Implementation notes: getDay, getMonth
 * --------------------------------------
 *
 */

int Date::getDay()
{
   return day;
}

/*
 * TODO function
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

Month Date::getMonth()
{
   return month;
}

int Date::getYear()
{
   return year;
}

/*
 * TODO function
 * Implementation notes: toString
 * ------------------------------
 * The toString method uses the getters to perform the translation into
 * day/month/year values.
 */

string Date::toString()
{
   // TODO
   string ans;
   switch (month)
   {
   case (1):
      ans = "Jan";
      break;
   case (2):
      ans = "Feb";
      break;
   case (3):
      ans = "Mar";
      break;
   case (4):
      ans = "Apr";
      break;
   case (5):
      ans = "May";
      break;
   case (6):
      ans = "Jun";
      break;
   case (7):
      ans = "Jul";
      break;
   case (8):
      ans = "Aug";
      break;
   case (9):
      ans = "Sep";
      break;
   case (10):
      ans = "Oct";
      break;
   case (11):
      ans = "Nov";
      break;
   case (12):
      ans = "Dec";
      break;
   }
   // cout << day << year;
   return to_string(day) + "-" + ans + "-" + to_string(year);
}

void Date::initDate(int daya, Month montha, int yyyya)
{
   day = daya;
   month = montha;
   year = yyyya;
}

Month operator++(Month &month, int)
{
   if (month != 12)
   {
      month = static_cast<Month>(month + 1);
      return month;
   }
   else
   {
      month = static_cast<Month>(1);
      return month;
   }
}

Date operator+(Date date, int delta)
{
   Month mon = date.getMonth();
   int day = date.getDay();
   int yea = date.getYear();
   int sumd1 = delta;
   if (daysInMonth(mon, yea) - day >= delta)
   {
      Date newdate(delta + day, date.getMonth(), date.getYear());
      return newdate;
   }
   else
   {
      sumd1 = delta - (daysInMonth(mon, yea) - day);
      if (mon == DECEMBER)
         yea++;
      mon++;
      while (sumd1 - daysInMonth(mon, yea) > 0)
      {
         sumd1 -= daysInMonth(mon, yea);
         mon++;
         if (mon == DECEMBER)
         {
            yea++;
         }
      }
      Date newd(sumd1, mon, yea);
      return newd;
   }
}

Date operator-(Date date, int delta)
{
   Month mon = date.getMonth();
   int day = date.getDay();
   int yea = date.getYear();
   int sumd1 = delta;
   if (day - delta > 0)
   {
      Date newdate(day - delta, mon, yea);
      return newdate;
   }
   else
   {
      int sumd1 = delta - day;
      if (mon == JANUARY)
         yea--;
      if (mon != 1)
      {
         mon = static_cast<Month>(mon - 1);
      }
      else
      {
         mon = static_cast<Month>(12);
      }
      while (sumd1 - daysInMonth(mon, yea) > 0)
      {
         sumd1 -= daysInMonth(mon, yea);
         if (mon == JANUARY)
            yea--;
         if (mon != 1)
         {
            mon = static_cast<Month>(mon - 1);
         }
         else
         {
            mon = static_cast<Month>(12);
         }
         if (mon == JANUARY)
            yea--;
      }
      Date newd(daysInMonth(mon, yea) - sumd1, mon, yea);
      return newd;
   }
}

int operator-(Date d1, Date d2)
{
   Date big, small;
   int re;
   if (d1 > d2)
   {
      big = d1;
      small = d2;
   }
   else if (d1 < d2)
   {
      big = d2;
      small = d1;
   }
   else
      return 0;

   int bigsum = 0;
   for (Month i = JANUARY; i < big.month; i++)
   {
      bigsum += daysInMonth(i, big.year);
   }
   bigsum = big.day + bigsum;

   int smallsum = 0;
   for (Month i = JANUARY; i < small.month; i++)
   {
      smallsum += daysInMonth(i, small.year);
   }
   smallsum = small.day + smallsum;

   int yeardif = big.getYear() - 1;
   while (yeardif - small.getYear() >= 0)
   {
      if (isLeapYear(yeardif))
         bigsum += 366;
      else
         bigsum += 365;
      yeardif -= 1;
   }
   re = bigsum - smallsum;
   if (d1 > d2)
   {
      return re;
   }
   else
   {
      return -re;
   }
}

Date &operator+=(Date &date, int delta)
{
   // TODO
   return date = date + delta;
}

Date &operator-=(Date &date, int delta)
{
   // TODO
   return date = date - delta;
}

Date operator++(Date &date)
{
   // TODO
   return date = (date + 1);
}

Date operator++(Date &date, int)
{
   // TODO
   Date da = date;
   date = date + 1;
   return da;
}

Date operator--(Date &date)
{
   // TODO
   return date = (date - 1);
}

Date operator--(Date &date, int)
{
   // TODO
   Date da = date;
   date = date - 1;
   return da;
}

bool operator==(Date d1, Date d2)
{
   // TODO
   if (d1.getDay() == d2.getDay() && d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth())
      return true;
   else
      return false;
}

bool operator!=(Date d1, Date d2)
{
   // TODO
   return !(d1 == d2);
}

bool operator<(Date d1, Date d2)
{
   // TODO
   if (d1.getYear() > d2.getYear())
      return false;
   else if (d2.getYear() > d1.getYear())
      return true;
   else
   {
      int sumd1 = 0;
      for (Month i = JANUARY; i < d1.getMonth(); i++)
      {
         sumd1 += daysInMonth(i, d1.getYear());
      }
      sumd1 = d1.getDay() + sumd1;
      int sumd2 = 0;
      for (Month i = JANUARY; i < d2.getMonth(); i++)
      {
         sumd2 += daysInMonth(i, d2.getYear());
      }
      sumd2 = d2.getDay() + sumd2;
      if (sumd1 < sumd2)
         return true;
      else
         return false;
   }
}

bool operator<=(Date d1, Date d2)
{
   // TODO
   return !(d1 > d2);
}

bool operator>(Date d1, Date d2)
{
   // TODO
   if (d1.getYear() > d2.getYear())
      return true;
   else if (d1.getYear() < d2.getYear())
      return false;
   else
   {
      int sumd1 = 0;
      for (Month i = JANUARY; i < d1.getMonth(); i++)
      {
         sumd1 += daysInMonth(i, d1.getYear());
      }
      sumd1 = d1.getDay() + sumd1;
      int sumd2 = 0;
      for (Month i = JANUARY; i < d2.getMonth(); i++)
      {
         sumd2 += daysInMonth(i, d2.getYear());
      }
      sumd2 = d2.getDay() + sumd2;
      if (sumd1 > sumd2)
         return true;
      else
         return false;
   }
}

bool operator>=(Date d1, Date d2)
{
   // TODO
   return !(d1 < d2);
}

std::ostream &operator<<(std::ostream &os, Date date)
{
   // TODO
   return os << date.toString();
}

/*
 * TODO function
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function is a reasonably literal translation of the old rhyme:
 *
 *    Thirty days has September
 *    April, June, and November
 *    All the rest have 31
 *    Excepting February alone
 *    Which has 28 in fine
 *    And each leap year 29
 */

int daysInMonth(Month month, int year)
{
   switch (month)
   {
   case (1):
      return 31;
      break;
   case (2):
      if (isLeapYear(year))
         return 29;
      else
         return 28;
   case (3):
      return 31;
      break;
   case (4):
      return 30;
      break;
   case (5):
      return 31;
      break;
   case (6):
      return 30;
      break;
   case (7):
      return 31;
      break;
   case (8):
      return 31;
      break;
   case (9):
      return 30;
      break;
   case (10):
      return 31;
      break;
   case (11):
      return 30;
      break;
   case (12):
      return 31;
      break;
   }
   return 0;
}

/* TODO PART:
 * Implementation notes: isLeapYear
 * --------------------------------
 * This function simply encodes the rule for determining leap years:
 * a leap year is any year divisible by 4, except for years ending in 00,
 * in which case the year must be divisible by 400.
 */

bool isLeapYear(int year)
{
   // TODO
   if (year % 4 == 0)
   {
      if (year % 100 != 0)
      {
         return true;
      }
   }
   if (year % 400 == 0)
   {
      return true;
   }
   return false;
}

/* DO NOT modify this main() part */
int main()
{
   int id;
   cin >> id;
   int day, year;
   string mon;
   cin >> day >> mon >> year;

   if (id == 1)
   {
      for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1))
      {
         cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << endl;
      }
   }
   else if (id == 2)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding.toString() << endl;
   }
   else if (id == 3)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cin >> mon >> day >> year;
      Date kennedyAssassination(stringToMonth(mon), day, year);
      cin >> mon >> day >> year;
      Date newYearsEve(stringToMonth(mon), day, year);
      cin >> day >> mon >> year;
      Date inaugurationDay(day, stringToMonth(mon), year);
      cin >> day >> mon >> year;
      Date electionDay(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding << endl;
      cout << "kennedyAssassination = " << kennedyAssassination << endl;
      cout << boolalpha;
      cout << "moonLanding < kennedyAssassination = "
           << (moonLanding < kennedyAssassination) << endl;
      cout << "moonLanding > kennedyAssassination = "
           << (moonLanding > kennedyAssassination) << endl;
      cout << "moonLanding == kennedyAssassination = "
           << (moonLanding == kennedyAssassination) << endl;
      cout << "moonLanding == moonLanding = "
           << (moonLanding == moonLanding) << endl;
      cout << "inaugurationDay - electionDay = "
           << (inaugurationDay - electionDay) << endl;
      Date day = newYearsEve;
      cout << "New Year's Eve = " << day++ << endl;
      cout << "New Year's Day = " << day << endl;
      for (Date d = electionDay; d <= inaugurationDay; d++)
      {
         cout << d << endl;
      }
   }
}
