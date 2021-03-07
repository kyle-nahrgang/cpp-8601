#pragma once

#include <memory>

namespace cpp8601 {

class value {
  public:
    using handle = std::shared_ptr<value>;
    virtual bool is_timepoint() { return false; }
    virtual bool is_duration() { return false; }
    virtual bool is_interval() { return false; }

    virtual void parse(const std::string &str) = 0;
    bool try_parse(const std::string &str);

    const value &operator=(const std::string &rhs) {
        parse(rhs);
        return *this;
    }
};

using h_value = value::handle;

} // namespace cpp8601