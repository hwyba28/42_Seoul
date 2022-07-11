int ft_strcmp(char *s1, char *s2)
{
	int c;

	c = 0;
	while ((s1[c] == s2[c]) && (s1[c] != '\0') && (s2[c] != '\0'))
		c++;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
