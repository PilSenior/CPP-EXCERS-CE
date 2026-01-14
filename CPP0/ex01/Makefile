# Programın adı (Çıktı dosyası)
NAME = phonebook

# Derleyici ve Bayraklar
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Kaynak dosyalar
SRC = main.cpp Phonebook.cpp Contacts.cpp

# Obje dosyaları (Kaynak dosyalardan otomatik üretilir)
OBJ = $(SRC:.cpp=.o)

# Renkler (Opsiyonel: Çıktının güzel görünmesi için)
GREEN = \033[0;32m
RESET = \033[0m

# --- KURALLAR ---

# 'make' yazınca çalışacak varsayılan kural
all: $(NAME)

# Programı derleme kuralı
$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects and creating executable...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation successful! Run ./$(NAME) to start.$(RESET)"

# .cpp dosyalarını .o dosyalarına çevirme kuralı
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Temizlik kuralları
clean:
	@echo "Removing object files..."
	rm -f $(OBJ)

fclean: clean
	@echo "Removing executable..."
	rm -f $(NAME)

re: fclean all

# Dosya ismiyle çakışmayı önlemek için
.PHONY: all clean fclean re