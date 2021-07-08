SRCS    =   ft_atoi.c ft_char.c \
			ft_flags_pars.c ft_printf.c \
			ft_utils.c ft_string.c \
			ft_utils2.c ft_number.c \
			ft_uns_numb.c ft_pointer.c \
			ft_hex.c ft_hex_reduction.c \
			ft_number_reduction.c ft_p_reduction.c \

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

bonus:	all

re:         fclean  all

.PHONY:     all clean bonus fclean  re