CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
OBJ_DIR = .src
TARGET = bsq

CFLAGS	= -Wall -Wextra -Werror
SRCS 	= $(notdir $(wildcard $(SRC_DIR)/*.c)) # wildcard로 SRC_DIR에서 *.c로 된 파일들 목록을 뽑아낸 뒤에 notdir로 파일 이름만 뽑아낸다. 
OBJ 	= $(SRCS:.c = .o)
DEPS 	= $(SRCS:.c = .d) //dependencies

OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))
DEPS 	= $(OBJECTS:.o = .d)

all: $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	$(cc) $(CFLAGS) -c $< -o $(TARGET) $(LDFLAGS)

clean: 
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS) 

.PHONY: clean all 