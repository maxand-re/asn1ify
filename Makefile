PREFIX ?= /usr

all:
	@echo Run \'make install\' to install asn1ify.

install:
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@cp -p asn1ify $(DESTDIR)$(PREFIX)/bin/asn1ify
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/asn1ify

uninstall:
	@rm -rf $(DESTDIR)$(PREFIX)/bin/asn1ify