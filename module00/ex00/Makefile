CC = c++

CPPFLAGS = -Wall -Wextra -Werror

NAME = megaphone

# Source files
SRCS = megaphone.cpp

# Object files
OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

# Link object files to create the executable
${NAME}: ${OBJS}
	${CC} ${CPPFLAGS} -o ${NAME} ${OBJS}

# Compile source cpp files into object files
%.o: %.cpp
	${CC} ${CPPFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
