int	ft_str_is_lowercase(char *str)
{
    int c;

    c = 0;
    while (str[c] != '\0')//소문자알파벳이 아닌게 하나라도 나오면 종료.
    {
        if ((str[c] < 'a') || (str[c] > 'z'))
            return (0);
        c++;
    }
    return (1);
}
