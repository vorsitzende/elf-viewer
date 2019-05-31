# Multipurpose General Makefile
# Claudia Jughashvili, 2019

CC            := gcc
CPP           := g++
LD            := ld
AS            := nasm
AR            := ar
STRIP         := strip

INC           := inc
OBJDIR        := obj
SRCDIR        := src
OUTDIR        := bin
SRC           := $(notdir $(shell find $(SRCDIR) -maxdepth 1 -name '*.c'))
OBJ           := $(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))
OUT           := $(OUTDIR)/elfview
CFLAGS        := -c -Iinc -Wall -Os
LFLAGS        := -lcurses

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $< $(CFLAGS) -o $@

all           : $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(OUT)

.PHONY        : clean

clean         :
	rm -f $(OBJ) $(OUT)
