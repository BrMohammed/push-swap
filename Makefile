NAME = push_swap
NAME1 = cheker
# -fsanitize=address
CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = push_swap.c 
FILES2 = cheker.c
SRC_FILES=$(addprefix src/, lstnew.c ft_strcmp.c ft_atoi.c operations.c operations2.c operations3.c insert_the_index.c less_than_5.c more_than_5.c ft_strjoin.c)
RM = rm -f

#bash tester.sh ../../push-swap ...  

all : $(NAME)
cheker : $(NAME1)

$(NAME):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES) $(SRC_FILES)

$(NAME1):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME1) $(FILES2) $(SRC_FILES)

clean :
	@$(RM) $(NAME)

clean_cheker :
	@$(RM) $(NAME1)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

recheker : clean_cheker cheker

#  github bigin
# git pull --rebase origin main
ADD = git add .

read :=	@echo "Add Commit Plz !!" && read -p "-> " enter \
		&& git commit -m $${enter}

PU = git push

commit = git log --graph --oneline --decorate HEAD^..HEAD

push :
	@$(commit)
	@$(ADD)
	$(read)
	$(PU)
