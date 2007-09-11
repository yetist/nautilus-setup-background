INCLUDES =						\
	-DG_LOG_DOMAIN=\"Nautilus-Setup-Background\"	\
	-DDATADIR=\"$(datadir)\"			\
	-DGNOMELOCALEDIR=\""$(datadir)/locale"\" 	\
	-I$(top_srcdir)					\
	-I$(top_builddir)				\
	$(WARN_CFLAGS)                                  \
	-Werror                                         \
	$(DISABLE_DEPRECATED_CFLAGS)			\
	$(NAUTILUS_CFLAGS)				\
	$(GCONF_CFLAGS)					\
	$(GNOMEDESKTOP_CFLAGS)

# FIXME: get this from the .pc file
nautilus_extensiondir=$(libdir)/nautilus/extensions-1.0

nautilus_extension_LTLIBRARIES=libnautilus-setup-background.la

libnautilus_setup_background_la_SOURCES = \
	nautilus-setup-background.c       \
	nautilus-setup-background.h       \
	setup-background.c

libnautilus_setup_background_la_LDFLAGS = -module -avoid-version
libnautilus_setup_background_la_LIBADD  = $(NAUTILUS_LIBS) $(GNOMEVFS_LIBS) $(GCONF_LIBS) $(GNOMEDESKTOP_LIBS)
