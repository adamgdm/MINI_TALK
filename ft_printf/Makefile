SRC = Library/ft_putchar_fd.c Library/ft_putnbr_fd.c Library/ft_putu_fd.c Library/ft_printp_fd.c Library/ft_puthex_fd.c Library/ft_putstr_fd.c ft_printf.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o) 

CC = cc

NAME = libftprintf.a
	
all : $(NAME)	

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo "Creation of the Library: SUCCESSFUL"

clean :
	@echo "Deleting object files"
	@rm -rf $(OBJ)
	@echo "Deletion of object files: SUCCESSFUL"

fclean :
	@echo "Deleting Library and object files"
	@rm -rf $(OBJ) $(NAME)
	@echo "Deletion of library and object files: SUCCESSFUL"

re : fclean all

.PHONY : all clean fclean re
