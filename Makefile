CC=gcc -g
#TRGS = client_basic server_basic struct_client struct_server
#OBJS = $(TRGS:%=%.o)
#SRCS = $(OBJS:%.o=%.c)
#SRC=$(wildcard *.c)
#$(TRGS) : $(SRC)
#	$(CC) -o $@ $^ 
TARGET=$(foreach i,$(shell echo *.c), $(basename $i))

.PHONY:all
all: $(foreach i,$(shell echo *.c),$(basename $i))
%:	%.o

	$(CC) -o $@ $^


clean: 
	rm $(TARGET) 
