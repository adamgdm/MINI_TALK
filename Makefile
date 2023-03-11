SRC_SER = server.c

SRC_CNT = client.c 

SRC_PRT = ft_printf/Library/ft_putchar_fd.c ft_printf/Library/ft_putnbr_fd.c ft_printf/Library/ft_putu_fd.c ft_printf/Library/ft_printp_fd.c ft_printf/Library/ft_puthex_fd.c ft_printf/Library/ft_putstr_fd.c ft_printf/ft_printf.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

CLIENT = client

SERVER = server

PRINTFLIB = printflib.a
	
all : $(PRINTFLIB) $(CLIENT) $(SERVER)

$(PRINTFLIB) : $(SRC_PRT=.c=.o)
	ar -rc $(PRINTFLIB) $(SRC_PRT=.c=.o)

$(SERVER) : $(SRC_SER:.c=.o) $(PRINTFLIB)
	$(CC) $(CFLAGS) $(SRC_SER:.c=.o) -o $(SERVER)

$(CLIENT) : $(SRC_CNT:.c=.o) $(PRINTFLIB)
	$(CC) $(CFLAGS) $(SRC_CNT:.c=.o) -o $(CLIENT)

clean :
	@echo "Deleting object files"
	@rm -rf $(SRC_SER:.c=.o) $(SRC_CNT:.c=.o) $(SRC_PRT=.c=.o)
	@echo "Deletion of object files: SUCCESSFUL"

fclean :
	@echo "Deleting ft_printf/Library and object files"
	@rm -rf $(SRC_SER:.c=.o) $(SRC_CNT:.c=.o) $(SRC_PRT=.c=.o) server client printflib.a
	@echo "Deletion of ft_printf/Library and object files: SUCCESSFUL"

re : fclean all

.PHONY : all clean fclean re
