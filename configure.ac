AC_INIT([tvm-rcx], [1.0.0], [kroc-bugs@kent.ac.uk])
AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE

CFLAGS="$CFLAGS -O2 -Wall -ffreestanding -fomit-frame-pointer -g"
CPPFLAGS="$CPPFLAGS"
LDFLAGS="$LDFLAGS -nostdlib"

AC_PROG_CC
AC_CHECK_TOOL([LD], [ld], [no])
AC_CHECK_TOOL([OBJCOPY], [objcopy], [no])

LIBGCC=`$CC $CFLAGS -print-libgcc-file-name`
AC_SUBST(LIBGCC)

AC_OUTPUT([Makefile])
