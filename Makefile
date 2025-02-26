CC = cc 

FLAGS = -Wall -Wextra -Werror

HLP_SRC = ./mandatory/Helpers.c \
			./mandatory/help.c

HLP_SRCB = ./bonus/Helpers_bonus.c \
			./bonus/help_bonus.c \
			./bonus/hlp_bonus.c




## Bonus !

CSRC_B = ./bonus/client_bonus.c 

SSRC_B = ./bonus/server_bonus.c

SERVER_B = server_B

CLIENT_B = client_B

COBJ_B = $(CSRC_B:.c=.o)

SOBJ_B = $(SSRC_B:.c=.o)


## Mandatory !

CSRC = ./mandatory/client.c

SSRC = ./mandatory/server.c

COBJ = $(CSRC:.c=.o)

SOBJ = $(SSRC:.c=.o)

SERVER = server

CLIENT = client

#################################################
# Mandatory !

all : $(CLIENT) $(SERVER)


$(CLIENT) : $(HLP_SRC) $(COBJ) ./mandatory/minitalk.h

	$(CC) $(FLAGS)  $(COBJ) $(HLP_SRC) -o $(CLIENT)


$(SERVER) : $(HLP_SRC) $(SOBJ) ./mandatory/minitalk.h

	$(CC) $(FLAGS) $(SOBJ) $(HLP_SRC) -o $(SERVER)


$(COBJ) : $(CSRC) ./mandatory/minitalk.h

	$(CC) $(FLAGS) -c $< -o $@


$(SOBJ) : $(SSRC) ./mandatory/minitalk.h

	$(CC) $(FLAGS) -c $< -o $@	

#################################################
# Bonus !

bonus : $(CLIENT_B) $(SERVER_B)

$(CLIENT_B) : $(HLP_SRCB) $(COBJ_B) ./bonus/minitalk_bonus.h

	$(CC) $(FLAGS)  $(COBJ_B) $(HLP_SRCB) -o $(CLIENT_B)


$(SERVER_B) : $(HLP_SRCB) $(SOBJ_B) ./bonus/minitalk_bonus.h

	$(CC) $(FLAGS) $(SOBJ_B) $(HLP_SRCB) -o $(SERVER_B)


$(COBJ_B) : $(CSRC_B) ./bonus/minitalk_bonus.h

	$(CC) $(FLAGS) -c $< -o $@


$(SOBJ_B) : $(SSRC_B) ./bonus/minitalk_bonus.h

	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -f $(COBJ_B) $(SOBJ_B) $(COBJ) $(SOBJ)

fclean: clean
	rm -f $(SERVER_B) $(CLIENT_B) $(SERVER) $(CLIENT)

re : fclean all