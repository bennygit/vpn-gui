# vpn-gui version
VERSION = 0.0.1

# path
PREFIX = /usr
MANPREFIX = ${PREFIX}/share/man


# includes and libs depedencies
GTKINC=$(shell pkg-config --cflags gtk+-3.0)
GTKLIB=$(shell pkg-config --libs gtk+-3.0 )

INCS = -I. -I/usr/include ${GTKINC}
LIBS = -L/usr/lib -lc ${GTKLIB}
# flags
CPPFLAGS = -DVERSION=\"${VERSION}\"
CFLAGS = -std=c99 -Os ${INCS} ${CPPFLAGS}
LDFLAGS = -s ${LIBS}

CC = cc

