#include <unistd.h>

// Description: prints a string to the standard output.
void ft_print_str(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}
