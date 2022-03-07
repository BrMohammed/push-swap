NAME = push_swap
NAME1 = checker
# -fsanitize=address
CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = push_swap.c 
FILES2 = cheker_bonus.c
SRC_FILES=$(addprefix src/, lstnew.c ft_strcmp.c ft_atoi.c operations.c operations2.c operations3.c insert_the_index.c less_than_5.c more_than_5.c ft_strjoin.c get_next_line_utils.c get_next_line.c)
RM = rm -f

all : $(NAME)
bonus : $(NAME1)

$(NAME):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES) $(SRC_FILES)

$(NAME1):  $(FILES2)
	$(CC) $(CFLAGS)  -o $(NAME1) $(FILES2) $(SRC_FILES)

clean :
	@$(RM) $(NAME)

clean_bonus :
	@$(RM) $(NAME1)

fclean :
	@$(RM) $(NAME) $(NAME1)

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
