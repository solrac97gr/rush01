// Description: Extract the constraints from the argument.
void ft_extract_constraints(int *constraints, char *arg)
{
    int i = 0;
    while (i < 16)
    {
        constraints[i] = arg[i * 2] - '0';
        i++;
    }
}