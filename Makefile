CC = cc 

FLAGS = -Wall -Wextra -Werror

HLP_SRC = ./Helpers/Helpers.o

## Bonus !

CSRC_B = client_bonus.c 

SSRC_B = server_bonus.c

SERVER_B = server_B

CLIENT_B = client_B

COBJ_B = $(CSRC_B: .c = .o)

SOBJ_B = $(SSRC_B: .c = .o)


## Mandatory !

CSRC = client.c 

SSRC = server.c

COBJ = $(CSRC: .c = .o)

SOBJ = $(SSRC: .c = .o)

SERVER = server

CLIENT = client




all : $(CLIENT) $(SERVER)

$(CLIENT) : $(HLP_SRC) $(COBJ) minitalk.h

	$(CC) $(FLAGS)  $(COBJ) $(HLP_SRC) -o $(CLIENT)


$(SERVER) : $(HLP_SRC) $(SOBJ) minitalk.h

	$(CC) $(FLAGS) $(SOBJ) $(HLP_SRC) -o $(SERVER)



bonus : $(CLIENT_B) $(SERVER_B)

$(CLIENT_B) : $(HLP_SRC) $(COBJ_B) minitalk_bonus.h

	$(CC) $(FLAGS)  $(COBJ_B) $(HLP_SRC) -o $(CLIENT_B)


$(SERVER_B) : $(HLP_SRC) $(SOBJ_B) minitalk_bonus.h

	$(CC) $(FLAGS) $(SOBJ_B) $(HLP_SRC) -o $(SERVER_B)


clean:
	rm -f $(COBJ_B) $(SOBJ_B) $(COBJ) $(SOBJ)

fclean: clean
	rm -f $(SERVER_B) $(CLIENT_B) $(SERVER) $(CLIENT) 