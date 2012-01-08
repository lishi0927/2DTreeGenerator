# GNU Make solution makefile autogenerated by Premake
# Type "make help" for usage help

ifndef config
  config=debug
endif
export config

PROJECTS := 2DTreeGenerator

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

2DTreeGenerator: 
	@echo "==== Building 2DTreeGenerator ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f 2DTreeGenerator.make

clean:
	@${MAKE} --no-print-directory -C . -f 2DTreeGenerator.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug"
	@echo "   release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   2DTreeGenerator"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
