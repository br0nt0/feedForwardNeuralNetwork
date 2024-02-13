.PHONY: all unitTestConf clean cleanTests format unitTest gcovr

BUILD_DIR = build
TEST_BUILD_DIR := ${BUILD_DIR}/utest

all: unitTest

${TEST_BUILD_DIR}/Makefile:
	cmake \
		-B${TEST_BUILD_DIR} \
		-G "Unix Makefiles" \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_RULE_MESSAGES:BOOL=ON

unitTestConf: ${TEST_BUILD_DIR}/Makefile

unitTest: unitTestConf	
	$(MAKE) -C ${TEST_BUILD_DIR} --no-print-directory

gcovr: unitTestConf
	$(MAKE) -C ${TEST_BUILD_DIR} coverage --no-print-directory

FIND := "/usr/bin/find"
SRCS := $(shell ${FIND} . -name '*.[ch]' -or -name '*.[ch]pp')
%.format: %
	clang-format --style=GNU -i $<
format: $(addsuffix .format, ${SRCS})

cleanTests:
	@rm -rf $(TEST_BUILD_DIR)
	@rm -rf $(wildcard *.gcov) || true

clean: cleanTests
	@rm -rf $(BUILD_DIR)/${BUILD_TYPE}
