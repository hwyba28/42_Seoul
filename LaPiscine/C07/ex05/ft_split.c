int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}
//strstr 함수
int contain_str(char *str, char *find_str)
{
    int i;
    int j;
    
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i + j] == find_str[j] && str[i + j] != '\0')
        {
            if (str1[i] == find_str[j])
            j++;
        }
        i++;
    }
}

char **ft_split(char *str, char *charset)
{
    
    int i;
    
    i = 0;
    while (i < ft_strlen(charset))
    {
        
        i++;
    }
    if (str[i] == charset[0])
}
