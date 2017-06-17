# Copyright 2017 Fred Sundvik
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include $(TMK_PATH)/protocol.mk

TEST_PATH=tests/$(TEST)

$(TEST)_SRC= \
	$(TEST_PATH)/test.cpp \
	$(TMK_COMMON_SRC) \
	$(QUANTUM_SRC) \
	tests/test_common/matrix.c \
	tests/test_common/test_driver.cpp \
	tests/test_common/keyboard_report_util.cpp
$(TEST)_DEFS=$(TMK_COMMON_DEFS)
$(TEST)_CONFIG=$(TEST_PATH)/config.h
VPATH+=$(TOP_DIR)/tests/test_common
