#include <iostream>

class TimeSpan
{
private:
  int hours;
  int minutes;
  int seconds;

  int convertToSeconds(int hours, int minutes, int seconds) const;

public:
  TimeSpan();
  TimeSpan(double hours, double minutes, double seconds);
  TimeSpan(double hours, double minutes);
  TimeSpan(double hours);

  bool setTime(int hours, int minutes, int seconds);
  bool setTime(double hours, double minutes, double seconds);

  int getHours() const;
  int getMinutes() const;
  int getSeconds() const;

  bool operator==(const TimeSpan &timeSpan) const;
  bool operator!=(const TimeSpan &timeSpan) const;

  TimeSpan operator+(const TimeSpan &timeSpan) const;
  TimeSpan operator-(const TimeSpan &timeSpan) const;
  TimeSpan &operator+=(const TimeSpan &timeSpan);
  TimeSpan &operator-=(const TimeSpan &timeSpan);

  TimeSpan operator-() const;

  friend std::ostream &operator<<(std::ostream &ostream, const TimeSpan &timeSpan);
  friend std::istream &operator>>(std::istream &istream, TimeSpan &timeSpan);
};

const int TIME_UNIT = 60;