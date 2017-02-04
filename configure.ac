AC_INIT(ferro, 1.1, [http://sourceforge.net/tracker/?func=add&group_id=235817&atid=1097912])

AC_PREREQ([2.59])
AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_HEADER(config.h)


AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_CXXCPP
AC_PROG_INSTALL
AC_PROG_LIBTOOL

AX_BOOST_BASE([1.33.1])
AC_CHECK_LIB(iconv, libiconv_open, [LDFLAGS="$LDFLAGS -liconv"])

AC_CONFIG_FILES([Makefile ferro/Makefile tools/Makefile])
AC_OUTPUT

echo "Configuration done. Now type \"make\"."

