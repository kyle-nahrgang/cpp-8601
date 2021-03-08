#pragma once

#include <stdexcept>

namespace cpp8601 {

class bad_value_exception : public std::runtime_error {
  public:
    bad_value_exception(const std::string &what) : std::runtime_error(what) {}
};

} // namespace cpp8601