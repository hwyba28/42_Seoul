char *ft_strlowcase(char *str)
{
	int c;
	c = 0;
    int diff;
    diff = 'a'-'A';
    
	while (str[c] != '\0')
	{
		if ((str[c] >= 'A') && (str[c] <= 'Z'))
			str[c] += diff;
		c++;
	}
	return (str);
}
