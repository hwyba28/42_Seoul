#include <unistd.h>

void	ft_putstr(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		write(1, &str[c], 1);
		c++;
	}
	write(1, "\n", 1);
}

void	swap(char *a, char *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
    *b = tmp;
}

char   *strcbn(char **str, int length)
{
    int i;
    int j;
    char *result;
    
    i = 1;
    while (i < length)
    {
        j = 0;
        while ( str[i][j] != '\n')
        {
            result += str[i][j];
            j++;
        }
        i++;
    }
    return result;
}

int		main(int argc, char **argv)
{
    char *result = strcbn(argv, argc);
    int i;
    int j;
    
    i = 0;
    while (result)
    {
        j = i+1;
        while ( j < argc ) {
        if( result[i] > result[j])
            swap(&result[i], &result[j]);
            j++;
        }
        i++;
    }
    i = 0;
    while (result[i] != '\0')
    {
        write(1, &result[i],1);
    }
    return (0);
}
