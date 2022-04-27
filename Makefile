SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o utils.o minitalk.h
	@$(CC) server.o utils.o $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build🤙\e[0m\n"

$(CLIENT) : client.o utils.o minitalk.h
	@$(CC) client.o utils.o $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build🤙\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

bonus:
	make all
clean :
	rm -f *.o
	@printf "\e[38;5;206m.o files deleted🚽\e[0m\n"

fclean: 
	make clean
	rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;206mBinaries deleted🗑\e[0m\n"

re: fclean all