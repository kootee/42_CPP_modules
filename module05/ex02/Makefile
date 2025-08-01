CC = c++

CPPFLAGS := -Wall -Wextra -Werror -std=c++11
DBFLAGS = -g

debug   ?= 0

NAME = bureaucrat

# Source files
SRCS = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	PresidentialPardonForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp

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
	rm -f ${OBJS}

fclean: clean
	rm -rf ${NAME}
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re
