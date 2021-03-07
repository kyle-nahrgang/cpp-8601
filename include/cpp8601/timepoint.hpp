#pragma once

#include "value.hpp"
#include <string>

namespace cpp8601 {

class timepoint : public value {
  public:
    timepoint();
    timepoint(const std::string &s);
    ~timepoint();

    bool is_timepoint() override { return true; }

    void parse(const std::string &str) override;
};

} // namespace cpp8601
