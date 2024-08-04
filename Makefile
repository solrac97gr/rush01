
cc:
	@cc -Wall -Wextra -Werror ex00/*.c -o ./a.out 
	@echo "Your program compile succesfully 📦 in the route: ./a.out"
	@echo "To run the program use: make run CASE=\"your case\"" or make example
nor:
	@norminette
example:
	make run CASE="4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
run:
	@./a.out "$(CASE)" | cat -e
clean:
	@rm -f ./a.out
	@echo "program removed 🧹"
