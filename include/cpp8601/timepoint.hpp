#pragma once

#include "value.hpp"
#include <ctime>
#include <string>
namespace cpp8601 {

enum class time_val_t { none, year, month, day, hour, minute, second, millisecond, tz_hour, tz_minute };

class timepoint : public value {
  private:
    int vals[9];

    void _parse(const std::string &str, size_t offset, time_val_t t);

  public:
    timepoint();
    timepoint(const std::string &s);
    ~timepoint();

    bool is_timepoint() override { return true; }

    void parse(const std::string &str) override;

    const int &get_year() const;
    const int &get_month() const;
    const int &get_day() const;
    const int &get_hour() const;
    const int &get_minute() const;
    const int &get_second() const;
    const int &get_millisecond() const;
    const int &get_tz_hour() const;
    const int &get_tz_minute() const;
};

} // namespace cpp8601
