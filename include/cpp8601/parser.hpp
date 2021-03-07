#pragma once

#include "value.hpp"
#include <string>

namespace cpp8601 {

class parser {
  private:
    parser() = delete;
    ~parser() = delete;

  public:
    static bool is_timepoint(const std::string &str);
    static bool is_duration(const std::string &str);
    static bool is_interval(const std::string &str);

    static h_value parse(const std::string &str);
};

} // namespace cpp8601