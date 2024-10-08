CC = c++

CPPFLAGS := -Wall -Wextra -Werror
DBFLAGS = -g

debug   ?= 0

NAME = Harl

# Source files
SRCS = main.cpp Harl.cpp

# Object files
OBJS = ${SRCS:.cpp=.o}

# Set debug
ifeq (${debug}, 1)
    CPPFLAGS += ${DBFLAGS}
endif

all: ${NAME}

# Link object files to create the executable
${NAME}: ${OBJS}
	${CC} ${CPPFLAGS} -o ${NAME} ${OBJS}

# Compile source cpp files into object files
%.o: %.cpp
	${CC} ${CPPFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${NAME}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
