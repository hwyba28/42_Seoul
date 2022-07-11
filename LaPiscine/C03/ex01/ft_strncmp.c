int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int c;
    
    c = 0;
    while (s1[c] != '\0' && s2[c] != s1[c] && c < n)
    {
        if (s1[c] != s2[c])
            break ;
        c++;
    }
    if (c == n)
        return (0);
    return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
