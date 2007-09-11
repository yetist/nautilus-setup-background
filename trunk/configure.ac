#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(nautilus-setup-background, 0.1, yetist@gmail.com)
AC_CONFIG_SRCDIR([src/setup-background.c])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([1.8 dist-bzip2 no-dist-gzip])

AC_PROG_LIBTOOL

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_INTLTOOL(0.18)


dnl ================================================================
dnl Checks for library functions.
dnl ================================================================

NAUTILUS_REQUIRED=2.6.0
EEL_REQUIRED=2.6.0
LIBGNOME_DESKTOP_REQUIRED=2.9.91
GLIB_REQUIRED=2.4.0

PKG_CHECK_MODULES(NAUTILUS, libnautilus-extension >= $NAUTILUS_REQUIRED glib-2.0 >= $GLIB_REQUIRED)
AC_SUBST(NAUTILUS_CFLAGS)
AC_SUBST(NAUTILUS_LIBS)

PKG_CHECK_MODULES(GCONF, gconf-2.0)
AC_SUBST(GCONF_CFLAGS)
AC_SUBST(GCONF_LIBS)

PKG_CHECK_MODULES(GNOMEDESKTOP, gnome-desktop-2.0 >= $LIBGNOME_DESKTOP_REQUIRED)
AC_SUBST(GNOMEDESKTOP_CFLAGS)
AC_SUBST(GNOMEDESKTOP_LIBS)


dnl ================================================================
dnl Gettext stuff.
dnl ================================================================

GETTEXT_PACKAGE=nautilus-setup-background
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Gettext package])

AM_GLIB_GNU_GETTEXT


AC_CONFIG_FILES([
  Makefile
  src/Makefile
  po/Makefile.in
])

AC_OUTPUT

echo "

Configuration:

        Source code location:   ${srcdir}
        Compiler:               ${CC}
"

