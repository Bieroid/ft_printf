SRCS    =   ft_atoi.c ft_char.c \
			ft_flags_pars.c ft_printf.c \
			ft_utils.c ft_string.c \
			ft_utils2.c \

OBJS    =   ${SRCS:.c=.o}

NAME    =   libftprintf.a

CFLAGS  =       -Wall -Wextra -Werror

CC              =       gcc

HEADER  =       ft_printf.h

RM      =   rm  -f

all:    ${NAME}

${NAME}:        ${OBJS}
	ar rc ${NAME} ${OBJS} ${HEADER}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean:     clean
	${RM} ${NAME}

re:         fclean  all

.PHONY:     all clean   fclean  re