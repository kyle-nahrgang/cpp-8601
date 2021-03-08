#include <cpp8601.hpp>
#include <cppunit/extensions/HelperMacros.h>

class cpp8601_parser_test_fixture : public CppUnit::TestFixture {
  private:
    CPPUNIT_TEST_SUITE(cpp8601_parser_test_fixture);
    CPPUNIT_TEST(is_timepoint_valid_dates);
    CPPUNIT_TEST(is_timepoint_valid_times);
    CPPUNIT_TEST(is_timepoint_valid_datetimes);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

    void is_timepoint_valid_dates();
    void is_timepoint_valid_times();
    void is_timepoint_valid_datetimes();
};

CPPUNIT_TEST_SUITE_REGISTRATION(cpp8601_parser_test_fixture);

void cpp8601_parser_test_fixture::setUp() {}
void cpp8601_parser_test_fixture::tearDown() {}

void cpp8601_parser_test_fixture::is_timepoint_valid_dates() {}

void cpp8601_parser_test_fixture::is_timepoint_valid_times() {
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T1347") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13:47") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T134730") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13:47:30") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("13:47:30") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13:47:30Z") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13:47:30+1234") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13:47:30+12:34") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13:47:30-1234") == true);
    CPPUNIT_ASSERT(cpp8601::parser::is_timepoint("T13:47:30-12:34") == true);
}

void cpp8601_parser_test_fixture::is_timepoint_valid_datetimes() {}