##############################################################################
#
# Zetta(c) (and rebranded) cameras makefile
#
# This file is part of the zettaconf distribution
#                                      (https://github.com/asoraruf/zettaconf)
# Copyright (c) 2017 Alessandro Soraruf.
#
# This program is free software: you can redistribute it and/or modify  
# it under the terms of the GNU General Public License as published by  
# the Free Software Foundation, version 2.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#
##############################################################################
#
# 'make depend'  uses makedepend to automatically generate dependencies 
#                (dependencies are added to end of Makefile)
# 'make'         build executable file 'zettaconf'
# 'make clean'   removes all .o and executable files
# 'make install' install executable file 'zettaconf' on the system
#
##############################################################################

CC       = gcc
CFLAGS   = -O3 -Wall
INCLUDES =
LFLAGS   =
LIBS     =
HDRS     = zetta_conf_files.h zetta_functions.h
SRCS     = zetta_conf_files.c zetta_functions.c main.c
OBJS     = $(SRCS:.c=.o)
DST_DIR  = /usr/local/bin
TARGET   = zettaconf

# Targets
.PHONY: depend clean all install

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

%.o : %.c $(HDRS) 
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -fr $(TARGET) $(TARGET).exe
	@rm -fr *.o

install:
	@cp $(TARGET) $(DST_DIR)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it