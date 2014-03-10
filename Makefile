# vpn-gui a little helper for my vpn-script
# See LICENSE file for copyright and license details.

include config.mk

SRC = vpn-gui.c
OBJ = ${SRC:.c=.o}

all: options vpn-gui

options:
	@echo vpn-gui build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

vpn-gui: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ vpn-gui.o ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f vpn-gui ${OBJ}

install: all
	@echo installing vpn-gui to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f vpn-gui ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/vpn-gui

uninstall:
	@echo removing vpn-gui executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/vpn-gui

.PHONY: all options clean install uninstall
