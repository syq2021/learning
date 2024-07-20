#include "mytime3.h"

#include <iostream>

Time::Time() { hours = minutes = 0; }

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}

void Time::AddMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::Addhr(int h) { hours += h; }

void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

Time Time::operator+(const Time &t) const {
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time Time::operator-(const Time &t) const {
  Time diff;
  int tol1, tol2;
  tol1 = t.minutes + 60 * t.hours;
  tol2 = minutes + 60 * hours;
  diff.minutes = (tol1 - tol2) % 60;
  diff.hours = (tol1 - tol2) / 60;
  return diff;
}

Time Time::operator*(double mult) const {
  Time res;
  long totalminutes = hours * mult * 60 + minutes * mult;
  res.hours = totalminutes / 60;
  res.minutes = totalminutes % 60;
  return res;
}

std::ostream &operator<<(std::ostream &os, const Time &t) {
  os << t.hours << " hours, " << t.minutes << " minutes";
  return os;
}

void Time::Show() const {
  std::cout << hours << " hours, " << minutes << " minutes";
}
