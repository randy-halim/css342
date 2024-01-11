# Invariants

- Stored seconds are in the interval `-60 <= x <= 60`, as ints
- Stored minutes are in the interval `-60 <= x <= 60`, as ints
- Stored hours are in the interval `0 >= x`, as ints (disregard int overflow)

# Calculating Times

Take for example `TimeSpan(1.5, 3, -10)`

1. Calculate `1.5` hours: 1 hour 30 minutes
2. Calculate `4` minutes: add 3 minutes, for 1 hour 34 minutes
3. Calculate `-10` seconds: subtract 10 seconds, for 1 hour 33 minutes 50 seconds

# Helper Methods (?)

- `TimeSpan::adjustHours` - parses hours into hours + minutes, uses setters
- `TimeSpan::adjustMinutes` - parses minutes into minutes + seconds, uses setters
- `TimeSpan::adjustSeconds` - parses seconds by rounding