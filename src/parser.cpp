#include <cpp8601/parser.hpp>
#include <cpp8601/timepoint.hpp>

using namespace cpp8601;

bool parser::is_timepoint(const std::string &str) {
    auto _v = parse(str);
    return (_v) ? _v->is_timepoint() : false;
}

bool parser::is_duration(const std::string &str) {
    auto _v = parse(str);
    return (_v) ? _v->is_duration() : false;
}

bool parser::is_interval(const std::string &str) {
    auto _v = parse(str);
    return (_v) ? _v->is_interval() : false;
}

h_value parser::parse(const std::string &str) {
    timepoint _tp;
    if (_tp.try_parse(str)) {
        return std::make_shared<timepoint>(str);
    }

    return nullptr;
}