CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
DBFLAGS = -g

debug   ?= 0

NAME = zombie

# Source files
SRCS = 

# Object files
OBJS = ${SRCS:.cpp=.o}

# Set debug
ifeq (${debug}, 1)
    CFLAGS = ${DBFLAGS} ${FLAGS}
endif

all: ${NAME}

# Link object files to create the executable
${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

# Compile source cpp files into object files
%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${NAME}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
