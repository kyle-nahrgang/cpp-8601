#include <cpp8601/value.hpp>

using namespace cpp8601;

bool value::try_parse(const std::string &str) {
    try {
        parse(str);
    } catch (...) {
        return false;
    }

    return true;
}
