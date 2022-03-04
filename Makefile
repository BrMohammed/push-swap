NAME = push_swap
# -fsanitize=address
CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = push_swap.c 
SRC_FILES=$(addprefix src/, lstnew.c ft_strcmp.c ft_atoi.c operations.c operations2.c operations3.c insert_the_index.c less_than_5.c more_than_5.c)
RM = rm -f

#bash tester.sh ../../push-swap ...  

all : $(NAME)

$(NAME):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES) $(SRC_FILES)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

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
