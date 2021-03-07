
if HAVE_CPPUNIT
BUILT_SOURCES = runner.o

runner.o:
	$(CXX) -c $(CXXFLAGS) $(CPPUNIT_CFLAGS) runner.cpp

TESTS = parser
check_PROGRAMS = $(TESTS)
endif

EXEEXT=.test
AM_DEFAULT_SOURCE_EXT = _test.cpp
AM_CXXFLAGS = -I$(top_srcdir)/include $(CPPUNIT_CFLAGS)
AM_LDFLAGS = runner.o $(CPPUNIT_LIBS) -ldl -L$(top_srcdir)/src -lcpp8601