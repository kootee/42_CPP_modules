CC = c++

CPPFLAGS := -Wall -Wextra -Werror -std=c++11
DBFLAGS = -g

debug   ?= 0

NAME = bureaucrat

# Source files
SRCS = src/main.cpp \
	src/Bureaucrat.cpp \
	src/AForm.cpp \
	src/PresidentialPardonForm.cpp \
	src/ShrubberyCreationForm.cpp \
	src/RobotomyRequestForm.cpp \
	src/Intern.cpp

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

# Compile source cpp files into object files
%.o: %.cpp
	${CC} ${CPPFLAGS} ${HEADERS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
