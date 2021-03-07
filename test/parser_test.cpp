#include <cpp8601.hpp>
#include <cppunit/extensions/HelperMacros.h>

class cpp8601_parser_test_fixture : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(cpp8601_parser_test_fixture);
    CPPUNIT_TEST(testTrue);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

    void testTrue();
};

void cpp8601_parser_test_fixture::setUp() {}
void cpp8601_parser_test_fixture::tearDown() {}
void cpp8601_parser_test_fixture::testTrue() {
    CPPUNIT_ASSERT(true);
}
