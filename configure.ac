AC_INIT(core3, 1.0)
AC_CANONICAL_SYSTEM

AC_CONFIG_AUX_DIR(build/unix/config)
AC_CONFIG_HEADER(config.h)

AM_INIT_AUTOMAKE

CXXFLAGS="$CXXFLAGS $C_EXTRA_FLAGS "

AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB

case "$host_cpu-$host_os" in
    *freebsd*)
      SYSTEM_INCLUDES="-I/usr/local/include"
      SYSTEM_LIBS="-lpthread -lexecinfo"
      USER_INCLUDES_PATH="/usr/local/include"
      USER_LIBS_PATH="/usr/local/lib"
      ;;
    *cygwin*)
      SYSTEM_INCLUDES=""
      SYSTEM_LIBS="-lpthread -lwsock32"
      USER_INCLUDES_PATH="/usr/local/include"
      USER_LIBS_PATH="/usr/local/lib"
      ;;
    *)
      SYSTEM_INCLUDES="" 
      SYSTEM_LIBS="-lrt -ldl -lpthread"
      USER_INCLUDES_PATH="/usr/local/include"
      USER_LIBS_PATH="/usr/local/lib"
esac

AC_SUBST(CFLAGS)
AC_SUBST(CXXFLAGS)

AC_SUBST(SYSTEM_INCLUDES)
AC_SUBST(SYSTEM_LIBS)

AC_SUBST(USER_INCLUDES_PATH)
AC_SUBST(USER_LIBS_PATH)

AC_OUTPUT(Makefile src/Makefile)