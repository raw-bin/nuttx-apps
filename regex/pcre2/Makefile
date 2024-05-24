include $(APPDIR)/Make.defs

PCRE2_VERSION 	= 10.43
PCRE2_UNPACK  	= unpack
PCRE2_TARBALL 	= pcre2-$(PCRE2_VERSION).tar.bz2
PCRE2_URL_BASE 	= https://github.com/PCRE2Project/pcre2/releases/download
PCRE2_URL 			= $(PCRE2_URL_BASE)/pcre2-$(PCRE2_VERSION)/$(PCRE2_TARBALL)

VPATH += $(PCRE2_UNPACK)

$(PCRE2_TARBALL):
	$(Q) echo "Downloading $(PCRE2_TARBALL)"
	$(Q) curl -O -L $(PCRE2_URL)

$(PCRE2_UNPACK): $(PCRE2_TARBALL)
	$(Q) echo "Unpacking $(PCRE2_TARBALL) to $(PCRE2_UNPACK)"
	$(Q) tar jxf $(PCRE2_TARBALL)
	$(Q) mv pcre2-$(PCRE2_VERSION) $(PCRE2_UNPACK)

context:: $(PCRE2_UNPACK)
	cmake 																									\
		-S $(PCRE2_UNPACK)																		\
		-B $(PCRE2_UNPACK)/build															\
		-DCMAKE_C_COMPILER=$(CC)															\
		-DCMAKE_C_FLAGS="$(CFLAGS)"														\
		-DCMAKE_C_COMPILER_WORKS=TRUE													\
		-DCMAKE_INSTALL_PREFIX=$(PCRE2_UNPACK)/install 				\
		-DPCRE2_STATIC_PIC=ON 																\
		-DPCRE2_BUILD_TESTS=OFF 															\
		-DPCRE2_BUILD_PCRE2GREP=OFF 													\
		-DPCRE2GREP_SUPPORT_JIT=OFF 													\
		-DPCRE2GREP_SUPPORT_CALLOUT=OFF 											\
		-DPCRE2GREP_SUPPORT_CALLOUT_FORK=OFF 									\
		-DPCRE2GREP_BUFSIZE="0" 															\
		-DPCRE2GREP_MAX_BUFSIZE="0" 													\
		-DPCRE2_SUPPORT_UNICODE=OFF  													\
		-DPCRE2_HEAP_LIMIT="100" 															\
		-DPCRE2_MATCH_LIMIT="100"
	cmake --build $(PCRE2_UNPACK)/build
	cmake --install $(PCRE2_UNPACK)/build
	
distclean::
	$(call DELDIR, $(PCRE2_UNPACK))
	$(call DELFILE, $(PCRE2_TARBALL))

include $(APPDIR)/Application.mk
