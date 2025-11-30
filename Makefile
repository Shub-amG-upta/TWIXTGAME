CC=gcc
CFLAGS=-Wall -Wextra -std=c11
SRCS=main.c game.c instructions.c win.c
OBJS=$(SRCS:.c=.o)
TARGET=twixt

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

re:
	make clean
	make all
