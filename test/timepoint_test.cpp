#include <cpp8601/exceptions.hpp>
#include <cpp8601/timepoint.hpp>
#include <cppunit/extensions/HelperMacros.h>

class cpp8601_timepoint_test_fixture : public CppUnit::TestFixture {
  private:
    CPPUNIT_TEST_SUITE(cpp8601_timepoint_test_fixture);
    CPPUNIT_TEST(timepoint_parse_time_T);
    CPPUNIT_TEST(timepoint_parse_time_no_T);
    CPPUNIT_TEST(timepoint_parse_date);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

    void timepoint_parse_time_T();
    void timepoint_parse_time_no_T();
    void timepoint_parse_date();
};

CPPUNIT_TEST_SUITE_REGISTRATION(cpp8601_timepoint_test_fixture);

void cpp8601_timepoint_test_fixture::setUp() {}
void cpp8601_timepoint_test_fixture::tearDown() {}

void cpp8601_timepoint_test_fixture::timepoint_parse_time_T() {
    cpp8601::timepoint tp;
    CPPUNIT_ASSERT_NO_THROW(tp.parse("T13")); // Thh
    CPPUNIT_ASSERT_EQUAL(13, tp.get_hour());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("T1337")); // Thhmm
    CPPUNIT_ASSERT_EQUAL(13, tp.get_hour());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("T133742")); // Thhmmss
    CPPUNIT_ASSERT_EQUAL(13, tp.get_hour());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_EQUAL(42, tp.get_second());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("T133742.123")); // Thhmmss.sss
    CPPUNIT_ASSERT_EQUAL(13, tp.get_hour());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_EQUAL(123, tp.get_millisecond());
}

void cpp8601_timepoint_test_fixture::timepoint_parse_time_no_T() {
    cpp8601::timepoint tp;
    CPPUNIT_ASSERT_THROW(tp.parse("13"), cpp8601::bad_value_exception);
    CPPUNIT_ASSERT_NO_THROW(tp.parse("13:37")); // Thhmm
    CPPUNIT_ASSERT_EQUAL(13, tp.get_hour());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("13:37:42")); // Thhmmss
    CPPUNIT_ASSERT_EQUAL(13, tp.get_hour());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_EQUAL(42, tp.get_second());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("13:37:42.123")); // Thhmmss.sss
    CPPUNIT_ASSERT_EQUAL(13, tp.get_hour());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_EQUAL(37, tp.get_minute());
    CPPUNIT_ASSERT_EQUAL(123, tp.get_millisecond());
}

void cpp8601_timepoint_test_fixture::timepoint_parse_date() {
    cpp8601::timepoint tp;
    CPPUNIT_ASSERT_NO_THROW(tp.parse("2021")); // yyyy
    CPPUNIT_ASSERT_EQUAL(2021, tp.get_year());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("2021-01")); // yyyy-mm
    CPPUNIT_ASSERT_EQUAL(2021, tp.get_year());
    CPPUNIT_ASSERT_EQUAL(01, tp.get_month());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("2021-01-02")); // yyyy-mm-dd
    CPPUNIT_ASSERT_EQUAL(2021, tp.get_year());
    CPPUNIT_ASSERT_EQUAL(01, tp.get_month());
    CPPUNIT_ASSERT_EQUAL(02, tp.get_day());
    CPPUNIT_ASSERT_NO_THROW(tp.parse("20210102")); // yyyymmdd
    CPPUNIT_ASSERT_EQUAL(2021, tp.get_year());
    CPPUNIT_ASSERT_EQUAL(01, tp.get_month());
    CPPUNIT_ASSERT_EQUAL(02, tp.get_day());
    CPPUNIT_ASSERT_THROW(tp.parse("202001"), cpp8601::bad_value_exception); // yyyymm explicitly not allowed
}