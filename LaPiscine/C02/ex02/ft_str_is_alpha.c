int ft_str_is_alpha(char *str)
{
    int c;

    c = 0;
    while (str[c] != '\0')
    {
        if ((str[c] < 'A') || (str[c] > 'Z' && str[c] < 'a') || (str[c] > 'z'))
            return (0);
        c++;
    }
    return (1);
}

//연산자우선순위()
//return 2번으로 해결/아스키코드범위/계속 반복검사while
