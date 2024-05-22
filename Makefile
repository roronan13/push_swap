NAME_P = push_swap

_SRCS_P = 	push_swap.c\
			push_swap_errors.c\
			push_swap_utils_errors.c\
			sort.c\
			sort_utils.c\
			split.c
_SRCS_I = 	swap_a.c\
			swap_b.c\
			ss.c\
			push_a.c\
			push_b.c\
			rotate_a.c\
			rotate_b.c\
			rr.c\
			reverse_rotate_a.c\
			reverse_rotate_b.c\
			rrr.c\
			utils_instructions.c

SRCS_P_DIR = push
SRCS_I_DIR = instructions
SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCS_I = $(addprefix $(SRCS_I_DIR)/, $(_SRCS_I))
SRCO_P = $(SRCS_P:.c=.o)
SRCO_I = $(SRCS_I:.c=.o)

FLAG = -Wall -Wextra -Werror -g3
INC = -I includes/

all : $(NAME_P)

$(NAME_P) : $(SRCO_P) | $(SRCO_I)
	gcc -o $(NAME_P) $(SRCO_P) $(SRCO_I)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_P)
	/bin/rm -f $(SRCO_I)

fclean : clean
	/bin/rm -f $(NAME_P)
	/bin/rm -f $(SRCO_P)
	/bin/rm -f $(SRCO_I)

re :
	make fclean
	make