EE_BIN = gstest.elf
EE_OBJS = gstest.o
EE_CFLAGS += -g

EE_LIBS += -lgskit_toolkit -lgskit -ldmakit
EE_LDFLAGS += -L$(GSKIT)/lib -s
EE_INCS += -I$(GSKIT)/include

all: $(EE_BIN)

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
