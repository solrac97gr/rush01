
cc:
	@cc -Wall -Wextra -Werror ex00/main.c -o ./a.out 
	@echo "Your program compile succesfully 📦: ./a.out"
nor:
	@norminette
clean:
	@rm -f ./a.out
	@echo "program removed 🧹"
