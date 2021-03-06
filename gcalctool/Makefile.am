## Process this file with automake to produce Makefile.in

INCLUDES = \
	-I$(includedir) \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_PIXMAP_DIR=\""$(prefix)/$(DATADIRNAME)/pixmaps"\" \
	$(PACKAGE_CFLAGS) \
	$(GNOME_UTILS_CFLAGS) \
	$(GCONF_CFLAGS)

bin_PROGRAMS = gcalctool

gcalctool_SOURCES = \
	calctool.c \
	calctool.h \
	display.c \
	dsfuns.c \
	dsdefs.h \
	get.c \
	functions.c \
	functions.h \
	graphics.c \
	mp.c \
	mpmath.c \
	mpmath.h \
	parser.c \
	parser.h \
	parser_mac.h \
	gtk.c \
	extern.h \
	ce_parser.c \
	ce_parser.h \
	ce_parser.tab.h \
	lr_parser.c \
	lr_parser.h \
	lr_parser.tab.h \
	syntax_translation.h \
	syntax_translation.c

gcalctool_LDADD = \
	$(PACKAGE_LIBS) \
	$(GNOME_UTILS_LIBS) \
	$(GCONF_LIBS) \
        libparser.a

libparser.a: \
	lex.ce.o\
	lex.lr.o\
	ce_parser.tab.o\
	lr_parser.tab.o\
	ce_parser.o\
	lr_parser.o
	ar r libparser.a $^

ce_parser.o: ce_parser.c ce_parser.h
	$(COMPILE) -c $(INCLUDES) -o $@ ce_parser.c

lr_parser.o: lr_parser.c lr_parser.h
	$(COMPILE) -c $(INCLUDES) -o $@ lr_parser.c

lex.ce.o: lex.ce.c
	$(COMPILE) -c $(INCLUDES) -o $@ $^

lex.lr.o: lex.lr.c
	$(COMPILE) -c $(INCLUDES) -o $@ $^

ce_parser.tab.o: ce_parser.tab.c
	$(COMPILE) -c $(INCLUDES) -o $@ $^

ce_parser.tab.c: ce_parser.y
	bison -d -p ce -d ce_parser.y

lr_parser.tab.o: lr_parser.tab.c
	$(COMPILE) -c $(INCLUDES) -o $@ $^

lr_parser.tab.c: lr_parser.y
	bison -d -p lr lr_parser.y

lex.ce.c: ce_parser.tab.c ce_tokeniser.l
	$(LEX) -i -Pce ce_tokeniser.l

lex.lr.c: lr_parser.tab.c lr_tokeniser.l
	$(LEX) -i -Plr lr_tokeniser.l

code-format: 
	ls *[ch] | xargs indent -nbad -bap -bbo -nbc -br\
	-brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -cp33 \
	-cs -d0 -di1 -nfc1 -nfca -hnl -i4 -ip0 -l75 -lp -npcs\
	-nprs -npsl -nut -saf -sai -saw -nsc -nsob -nss

man1_MANS = gcalctool.1

# Install a symlink between gcalctool and gnome-calculator
install-exec-hook:
	test -e "$(DESTDIR)$(bindir)/gnome-calculator" \
	|| (cd "$(DESTDIR)$(bindir)" && ln -s gcalctool gnome-calculator)

# Remove the symlink between gcalctool and gnome-calculator
uninstall-local:
	test -h "$(DESTDIR)$(bindir)/gnome-calculator" \
	&& rm -f "$(DESTDIR)$(bindir)/gnome-calculator"

EXTRA_DIST = \
	$(man1_MANS) \
	ce_parser.y \
	ce_tokeniser.l \
	lr_parser.y \
	lr_tokeniser.l
