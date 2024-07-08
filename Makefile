CC = gcc-10
CFLAGS = -Wall -Wextra -O2
AR = ar
ARFLAGS = rcs

LIB_NAME = libstats.a
LIB_SRC = stats.c
LIB_OBJ = $(LIB_SRC:.c=.o)

MAIN_SRC = main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)
EXECUTABLE = gaussian_generator

all: $(LIB_NAME) $(EXECUTABLE)

$(LIB_NAME): $(LIB_OBJ)
    $(AR) $(ARFLAGS) $@ $^

$(EXECUTABLE): $(MAIN_OBJ) $(LIB_NAME)
    $(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(LIB_OBJ) $(MAIN_OBJ) $(EXECUTABLE) $(LIB_NAME)

.PHONY: all clean
