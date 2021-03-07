#include <cpp8601/timepoint.hpp>

using namespace cpp8601;

timepoint::timepoint() {}
timepoint::timepoint(const std::string &s) {
    parse(s);
}

timepoint::~timepoint() {}

void timepoint::parse(const std::string &s){

};