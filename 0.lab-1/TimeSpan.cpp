#include "TimeSpan.h"
#include <iostream>
#include <cmath>

// helper methods
int TimeSpan::convertToSeconds(int hours, int minutes, int seconds) const
{
  return hours * TIME_UNIT * TIME_UNIT + minutes * TIME_UNIT + seconds;
}

// setters
bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
  return this->setTime((double)hours, (double)minutes, (double)seconds);
}
bool TimeSpan::setTime(double hours, double minutes, double seconds)
{
  double intPart, fractPart;

  seconds = round(seconds);

  fractPart = modf(hours, &intPart);
  minutes += fractPart * TIME_UNIT;

  fractPart = modf(minutes, &intPart);
  seconds += fractPart * TIME_UNIT;

  if (seconds >= TIME_UNIT)
  {
    minutes += seconds / TIME_UNIT;
    seconds = fmod(seconds, TIME_UNIT);
  }

  if (minutes >= TIME_UNIT)
  {
    hours += minutes / TIME_UNIT;
    minutes = fmod(minutes, TIME_UNIT);
  }

  if (minutes < -60 || minutes > 60 || seconds < -60 || minutes > 60)
  {
    return false;
  }
  else
  {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    return true;
  }
}

// getter
int TimeSpan::getHours() const
{
  return this->hours;
}
int TimeSpan::getMinutes() const
{
  if (this->minutes < 0)
  {
    return this->minutes + 60;
  }
  else
  {
    return this->minutes;
  }
}
int TimeSpan::getSeconds() const
{
  if (this->seconds < 0)
  {
    return this->seconds + 60;
  }
  else
  {
    return this->seconds;
  }
}

// constructors
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
  this->setTime(hours, minutes, seconds);
}
TimeSpan::TimeSpan(double hours, double minutes) : TimeSpan(hours, minutes, 0) {}
TimeSpan::TimeSpan(double hours) : TimeSpan(hours, 0, 0) {}
TimeSpan::TimeSpan() : TimeSpan(0, 0, 0) {}

// math operators
TimeSpan TimeSpan::operator+(const TimeSpan &timeSpan) const
{
  const int seconds = this->convertToSeconds(this->hours, this->minutes, this->seconds) + this->convertToSeconds(timeSpan.hours, timeSpan.minutes, timeSpan.seconds);
  const int hours = seconds / (TIME_UNIT * TIME_UNIT);
  const int minutes = (seconds / TIME_UNIT) % TIME_UNIT;
  const int secondsRemainder = seconds % TIME_UNIT;

  return TimeSpan(hours, minutes, secondsRemainder);
}
TimeSpan TimeSpan::operator-(const TimeSpan &timeSpan) const
{
  const int seconds = this->convertToSeconds(this->hours, this->minutes, this->seconds) - this->convertToSeconds(timeSpan.hours, timeSpan.minutes, timeSpan.seconds);
  const int hours = seconds / (TIME_UNIT * TIME_UNIT);
  const int minutes = (seconds / TIME_UNIT) % TIME_UNIT;
  const int secondsRemainder = seconds % TIME_UNIT;

  return TimeSpan(hours, minutes, secondsRemainder);
}
TimeSpan &TimeSpan::operator+=(const TimeSpan &timeSpan)
{
  *this = *this + timeSpan;
  return *this;
}
TimeSpan &TimeSpan::operator-=(const TimeSpan &timeSpan)
{
  *this = *this - timeSpan;
  return *this;
}

// unary negation operator
TimeSpan TimeSpan::operator-() const
{
  return TimeSpan(-this->hours, -this->minutes, -this->seconds);
}

// stream operators
std::ostream &operator<<(std::ostream &os, const TimeSpan &timeSpan)
{
  os << "Hours: " << timeSpan.getHours() << ", Minutes: " << timeSpan.getMinutes() << ", Seconds: " << timeSpan.getSeconds();
  return os;
}
std::istream &operator>>(std::istream &is, TimeSpan &timeSpan)
{
  int hours, minutes, seconds;
  is >> hours >> minutes >> seconds;
  timeSpan.setTime(hours, minutes, seconds);
  return is;
}

// comparison operators
bool TimeSpan::operator==(const TimeSpan &timeSpan) const
{
  if (this->hours == timeSpan.hours && this->minutes == timeSpan.minutes && this->seconds == timeSpan.seconds)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool TimeSpan::operator!=(const TimeSpan &timeSpan) const
{
  return !(*this != timeSpan);
}