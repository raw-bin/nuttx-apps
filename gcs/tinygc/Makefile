include $(APPDIR)/Make.defs

TINYGC_VERSION 	= 2_6
TINYGC_UNPACK  	= tinygc
TINYGC_TARBALL 	= tinygc-$(TINYGC_VERSION).zip
TINYGC_URL_BASE 	= https://github.com/ivmai/tinygc/archive/refs/tags
TINYGC_URL_BASE 	= https://github.com/ivmai/tinygc/archive/refs/tags/tinygc-$(TINYGC_VERSION)
TINYGC_URL 				= $(TINYGC_URL_BASE)/tinygc-$(TINYGC_VERSION).zip

VPATH += $(TINYGC_UNPACK)

$(TINYGC_TARBALL):
	$(Q) echo "Downloading $(TINYGC_TARBALL)"
	$(Q) curl -O -L $(TINYGC_URL)

$(TINYGC_UNPACK): $(TINYGC_TARBALL)
	$(Q) echo "Unpacking $(TINYGC_TARBALL) to $(TINYGC_UNPACK)"
	$(Q) unzip -d . $(TINYGC_TARBALL)
	$(Q) mv tinygc-tinygc-$(TINYGC_VERSION) $(TINYGC_UNPACK)

context:: $(TINYGC_UNPACK)

MAINSRC = $(TINYGC_UNPACK)/tinygc.c
CFLAGS += -DGC_THREADS -DGC_PRINT_STATS -DGC_CLIBDECL= -DGC_FASTCALL=

distclean::
	$(call DELDIR, $(TINYGC_UNPACK))
	$(call DELFILE, $(TINYGC_TARBALL))

include $(APPDIR)/Application.mk
