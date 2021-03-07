AC_PREREQ([2.68])
AC_INIT([cpp-8601], [0.0.1], [kyle.nahrgang@gmail.com], [cpp-8601], [https://github.com/kyle-nahrgang/cpp-8601])

AC_CONFIG_AUX_DIR(aux-dist)
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])

AC_PROG_MAKE_SET
AC_PROG_CXX
AC_LANG(C++)
AM_PROG_AR
LT_INIT

CXXFLAGS="-std=c++11 -fPIC"

AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_FILES([Makefile include/Makefile src/Makefile docs/Makefile])

# program and library checks below here
AC_CHECK_PROGS([DOXYGEN], [doxygen])
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])
AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([docs/Doxyfile])])

AC_OUTPUT