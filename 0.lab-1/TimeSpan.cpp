#include "TimeSpan.h"
#include <iostream>
#include <cmath>

// given either hours or minutes, derive the time unit underneath.
// effectively: hours -> the minutes component,
//         and: minutes -> the seconds component
int deriveSmallerTimeComponent(float input)
{
  // reference: https://stackoverflow.com/a/43045004
  // f(x) = (x - input_start) / (input_end - input_start)
  //         * (output_end - output_start) + output_start

  // input_start and input_end will be hardcoded to 0.0f and 1.0f
  float input_start = 0.0f;
  float input_end = 1.0f;

  // output_start and output_end will be hardcoded to 0.0f and 60.0f
  float output_start = 0.0f;
  float output_end = 60.0f;

  float input_range = input_end - input_start;
  float output_range = output_end - output_start;

  float result = (input - input_start) / input_range * output_range + output_start;
  return (int)round(result);
}
int deriveSmallerTimeComponent(double input)
{
  return deriveSmallerTimeComponent((float)input);
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
  if (hours < 0)
  {
    return false;
  }
  if (minutes > 60 || minutes < -60)
  {
    return false;
  }
  if (seconds > 60 || minutes < -60)
  {
    return false;
  }

  TimeSpan::hours = hours;
  TimeSpan::minutes = minutes;
  TimeSpan::seconds = seconds;

  return true;
}

TimeSpan::TimeSpan(int hours, int minutes, int seconds)
{
  setTime(hours, minutes, seconds);
}
TimeSpan::TimeSpan(float hours, float minutes, float seconds)
{
  int wholeHours = floor(hours);
  int wholeMinutes = floor(minutes);
  int wholeSeconds = round(seconds);
  int derivedMinutes = deriveSmallerTimeComponent(hours - (float)wholeHours);
  int derivedSeconds = deriveSmallerTimeComponent(minutes - (float)wholeHours);

  setTime(wholeHours, wholeMinutes + derivedMinutes, wholeSeconds + derivedSeconds);
}