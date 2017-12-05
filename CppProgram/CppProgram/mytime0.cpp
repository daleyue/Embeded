// mytime0.cpp  -- implementing Time methods
#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include "mytime0.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

//Time Time::Sum(const Time & t) const  // connot be Time &, reference
Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;  // program constructs a copy of sum before destroying it,calling function gets the copy
}

Time Time::operator-(const Time & t) const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time Time::operator*(double mult) const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

// option 1/2: following accessed t.minutes and t.hours explicitly, so it had to be a friend func
Time operator*(double mult, const Time & t)  // note: no 'friend' used
{
	Time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

/* option 2/2: w/o use friend fuction
//This version only uses the Time object t as a whole, letting a member function
//handle the private values, so this version doesn¡¯t have to be a friend.
Time operator*(double m, const Time & t)    // non-friend func
{
	return t * m;      // use t.operator*(m)
}
*/

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}

void Time::Show() const
{
	std::cout << hours << " hours," << minutes << " minutes";
}
