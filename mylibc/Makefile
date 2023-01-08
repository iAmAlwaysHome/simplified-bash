NAME		= mylibc.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar
ARFLAGS		= -rcs
RM			= rm -rf

INCS_DIR	= ./incs

MYLIBC_DIR		= ./srcs/mylibc
MYLIBC			= myatoi.c\
				mybzero.c\
				mycalloc.c\
				myisalnum.c\
				myisalpha.c\
				myisascii.c\
				myisdigit.c\
				myisprint.c\
				myitoa.c\
				mymemchr.c\
				mymemcmp.c\
				mymemcpy.c\
				mymemmove.c\
				mymemset.c\
				myputchar_fd.c\
				myputendl_fd.c\
				myputnbr_fd.c\
				myputstr_fd.c\
				mysplit.c\
				mystrchr.c\
				mystrdup.c\
				mystrjoin.c\
				mystrlcat.c\
				mystrlcpy.c\
				mystrlen.c\
				mystrmapi.c\
				mystrncmp.c\
				mystrnstr.c\
				mystrrchr.c\
				mystrtrim.c\
				mysubstr.c\
				mytolower.c\
				mytoupper.c\
				mylstsize.c\
				mylstadd_back.c\
				mylstadd_front.c\
				mylstclear.c\
				mylstdelone.c\
				mylstiter.c\
				mylstlast.c\
				mylstmap.c\
				mylstnew.c\
				get_first_heap.c\
				hcalloc.c\
				hfree.c\
				hmalloc.c\
				hobliterate.c\
				ptr_move.c\

GNL_DIR			= ./srcs/get_next_line
GNL				= get_next_line.c\
				get_next_line_utils.c

MYPRINTF_DIR	= ./srcs/myprintf
MYPRINTF		= myprintf.c\
				myprintf_put.c\
				myprint_format.c\
				myprint_arg.c

all: $(NAME)

$(NAME): mylibc gnl myprintf

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $^ -o $@
	$(AR) $(ARFLAGS) $(NAME) $@

mylibc: $(addprefix $(MYLIBC_DIR)/, $(MYLIBC:.c=.o))
myprintf: $(addprefix $(MYPRINTF_DIR)/, $(MYPRINTF:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

clean:
	$(RM) $(addprefix $(MYLIBC_DIR)/, $(MYLIBC:.c=.o))
	$(RM) $(addprefix $(MYPRINTF_DIR)/, $(MYPRINTF:.c=.o))
	$(RM) $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re mylibc gnl myprintf
