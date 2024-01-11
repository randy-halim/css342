class TimeSpan
{
private:
  // private fields
  int seconds{}; // -60 <= x <= 60
  int minutes{}; // -60 <= x <= 60
  int hours{};

public:
  // int constructors
  TimeSpan(int hours, int minutes, int seconds);
  TimeSpan(int seconds);
  TimeSpan(int minutes, int seconds);
  // float constructors
  TimeSpan(float hours, float minutes, float seconds);
  TimeSpan(float seconds);
  TimeSpan(float minutes, float hours);
  // double constructors
  TimeSpan(double hours, double minutes, double seconds);
  TimeSpan(double seconds);
  TimeSpan(double minutes, double hours);

  // assignment spec. required getters
  int getHours() const;
  int getMinutes() const;
  int getSeconds() const;

  // assignment spec. required setter
  bool setTime(int hours, int minutes, int seconds);
};