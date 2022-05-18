C = gcc
ASM = nasm
CFLAGS = -std=gnu11 -I includes

DEBUG ?= no
VERBOSE ?= no

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

ifeq ($(VERBOSE), no)
	CFLAGS += -w
endif

SRC = $(wildcard $(addsuffix /*.c, ./src))
ASRC = $(wildcard $(addsuffix /*.asm, ./src))

BUILD_DIR = ./build

OBJ = $(SRC:.c=.o)
OBJ += $(ASRC:.asm=.ao)

RES = $(BUILD_DIR)/kmlib.so

all: $(RES)

$(RES):	$(OBJ)
	@[ -d $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	@$(C) -shared -o $(RES) $(OBJ) -lrt
	@rm $(OBJ)

%.o: %.c
	@$(C) -o $@ -c $< $(CFLAGS)

%.ao: %.asm
	@$(ASM) -f elf64 -o $@ $<

ifeq ($(DEBUG), yes)
	@echo "\033[1;32m[debug build completed]\033[1;00m"
else
	@echo "\033[1;32m[release build completed]\033[1;00m"
endif

clean:
	@rm -rf $(BUILD_DIR)