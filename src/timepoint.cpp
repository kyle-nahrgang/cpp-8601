#include <cpp8601/exceptions.hpp>
#include <cpp8601/timepoint.hpp>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>

using namespace cpp8601;

timepoint::timepoint() {}
timepoint::timepoint(const std::string &str) : timepoint() {
    parse(str);
}

timepoint::~timepoint() {}

int natoi(const std::string &str, size_t n) {
    char i[n + 1];
    std::strncpy(i, str.data(), n);
    i[n + 1] = 0;
    return atoi(i);
}

size_t consecutive_digits(const std::string &str) {
    size_t count = 0;
    for (auto c : str) {
        if (std::isdigit(c))
            count++;
        else
            break;
    }
    return count;
}

const int &timepoint::get_year() const {
    return vals[(int)time_val_t::year];
}
const int &timepoint::get_month() const {
    return vals[(int)time_val_t::month];
}
const int &timepoint::get_day() const {
    return vals[(int)time_val_t::day];
}
const int &timepoint::get_hour() const {
    return vals[(int)time_val_t::hour];
}
const int &timepoint::get_minute() const {
    return vals[(int)time_val_t::minute];
}
const int &timepoint::get_second() const {
    return vals[(int)time_val_t::second];
}
const int &timepoint::get_millisecond() const {
    return vals[(int)time_val_t::millisecond];
}
const int &timepoint::get_tz_hour() const {
    return vals[(int)time_val_t::tz_hour];
}
const int &timepoint::get_tz_minute() const {
    return vals[(int)time_val_t::tz_minute];
}

void timepoint::_parse(const std::string &str, size_t offset, time_val_t t) {
    if (offset >= str.size()) {
        return;
    }

    std::string ss = str.substr(offset);
    size_t digits = consecutive_digits(ss);

    switch (t) {
    case time_val_t::none:
        if (ss.at(0) == 'T') {
            // if it starts with a T, then it is definitely supposed to be an hour value
            offset++;
            _parse(str, offset, time_val_t::hour);

        } else if (digits >= 4) {
            _parse(str, offset, time_val_t::year);

        } else if ((digits == 2) && (str.size() > 3)) {
            _parse(str, offset, time_val_t::hour);

        } else
            throw bad_value_exception("invalid value");

        break;

    case time_val_t::year:
        if (digits < 4)
            throw bad_value_exception("invalid year");

        vals[(int)t] = natoi(ss, 4);
        offset += 4;

        if (offset >= str.size())
            return;

        digits = consecutive_digits(str.substr(offset));
        switch (digits) {
        case 4:
            // mmdd
            _parse(str, offset, time_val_t::month);
            break;

        case 0:
            if (str.at(offset) == '-') {
                _parse(str, offset, time_val_t::month);
            } else if (str.at(offset) == 'W') {
            }
            break;

        default:
            throw bad_value_exception("unexpected date following year");
        }
        break;

    case time_val_t::month:
        if (ss.at(0) == '-') {
            offset++;
            _parse(str, offset, t);

        } else if (digits < 2) {
            throw new bad_value_exception("invalid month");

        } else {
            vals[(int)t] = natoi(ss, 2);
            offset += 2;
            _parse(str, offset, time_val_t::day);
        }
        break;

    case time_val_t::day:
        if (ss.at(0) == '-') {
            offset++;
            _parse(str, offset, t);

        } else if (digits < 2) {
            throw bad_value_exception("invalid day field");

        } else {
            vals[(int)t] = natoi(ss, 2);
            offset += 2;
            _parse(str, offset, time_val_t::none);
        }
        break;

    case time_val_t::hour:
        if (digits < 2)
            throw bad_value_exception("invalid hour");

        vals[(int)t] = natoi(ss, 2);
        offset += 2;
        _parse(str, offset, time_val_t::minute);
        break;

    case time_val_t::minute:
    case time_val_t::second:
        if (ss.at(0) == ':') {
            offset++;
            _parse(str, offset, t);
        } else if (digits < 2) {
            throw bad_value_exception("invalid minutes or seconds field");
        } else {
            vals[(int)t] = natoi(ss, 2);
            offset += 2;
            _parse(str, offset, (time_val_t)(((int)t) + 1));
        }
        break;

    case time_val_t::millisecond:
        if (ss.at(0) == '.') {
            offset++;
            _parse(str, offset, t);
        } else if (digits < 3) {
            throw bad_value_exception("invalid milliseconds field");
        } else {
            vals[(int)t] = natoi(ss, 3);
            offset += 3;
            _parse(str, offset, time_val_t::tz_hour);
        }
        break;

    case time_val_t::tz_hour:
        break;

    case time_val_t::tz_minute:
        break;

    default:
        throw bad_value_exception("unexpected time_val_t");
    }
}

void timepoint::parse(const std::string &str) {
    _parse(str, 0, time_val_t::none);
};
