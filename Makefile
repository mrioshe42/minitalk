CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

PRINTF_PATH = ft_printf
PRINTF_ARCHIVE = $(PRINTF_PATH)/libftprintf.a

NAME = client server
BONUS_NAME = client_bonus server_bonus


CLIENT_OBJS = $(CLIENT_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJS = $(SERVER_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(BONUS_NAME)

client: $(CLIENT_OBJS) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) $(PRINTF_ARCHIVE)

server: $(SERVER_OBJS) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) $(PRINTF_ARCHIVE)

client_bonus: $(CLIENT_BONUS_OBJS) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) $(PRINTF_ARCHIVE)

server_bonus: $(SERVER_BONUS_OBJS) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) $(PRINTF_ARCHIVE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PRINTF_ARCHIVE):
	$(MAKE) -C $(PRINTF_PATH)

clean:
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
