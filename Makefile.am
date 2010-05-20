AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../m4

CPPFLAGS = \
	-Ilibtvm \
	-I../../runtime/libtvm \
	@CPPFLAGS@
LDFLAGS = -Llibtvm @LDFLAGS@
LIBS = -ltvm @LIBGCC@ @LIBS@

noinst_PROGRAMS = tvm_rcx

tvm_rcx_SOURCES = \
	librcx.c \
	systime.c \
	tvm.c \
	tvm-rcx.c

%.coff: $(tvm_rcx_OBJECTS)
	$(LD) $(LDFLAGS) \
		-o $@ -T h8300.rcx \
		$(tvm_rcx_OBJECTS) \
		$(LIBS)

%.srec: %.coff
	$(OBJCOPY) -O srec $< $@

tvm_rcx: tvm-rcx.coff tvm-rcx.srec
	touch $@

# All the source files need libtvm to be built first.
$(tvm_rcx_SOURCES): libtvm/libtvm.a

# Rebuild libtvm if we've been reconfigured.
libtvm/libtvm.a: config.status
	rm -fr libtvm
	mkdir libtvm
	cd libtvm && ../../../runtime/libtvm/configure \
		--host=h8300-hitachi-coff \
		--with-memory-allocator=tlsf \
		--enable-custom-memory-ops \
		CFLAGS="@CFLAGS@" \
		LDFLAGS="@LDFLAGS@"
	$(MAKE) -C libtvm

CLEANFILES = \
	tvm_rcx \
	tvm-rcx.coff tvm-rcx.srec

distclean-local:
	rm -Rf libtvm
