CC = c++

CPPFLAGS := -Wall -Wextra -Werror -std=c++11
DBFLAGS = -g

debug   ?= 0

NAME = materia

# Source files
SRCS = src/main.cpp \
	src/AMateria.cpp \
	src/Character.cpp \
	src/Cure.cpp \
	src/Ice.cpp \
	src/MateriaSource.cpp \
	src/OldMateriaList.cpp \
	src/Node.cpp

HEADERS = -I ./include

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
	@echo "\033[1;3;32mFinished building executable ${NAME}!\033[0m"

# Compile source cpp files into object files
%.o: %.cpp
	${CC} ${CPPFLAGS} ${HEADERS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
