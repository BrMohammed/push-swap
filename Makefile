NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = push_swap.c lstnew.c ft_strcmp.c ft_atoi.c

RM = rm -f


$(NAME):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES)
	
all : $(NAME)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

#  github bigin

ADD = git add .

read :=	@echo "Add Commit Plz !!" && read -p "-> " enter \
		&& git commit -m $${enter}

PU = git push origin master

commit = git log --graph --oneline --decorate HEAD^..HEAD

push :
	@$(commit)
	@$(ADD)
	$(read)
	$(PU)