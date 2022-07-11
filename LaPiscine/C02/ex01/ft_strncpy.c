char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int idx;

    idx = 0;
    while (idx < n && src[idx] != '\0')
    {
        dest[idx] = src[idx];
        idx++;
    }
    while (idx < n)
    {
        dest[idx] = '\0';
        idx++;
    }

	return (dest);
}

//strncpy는 범위 복사인데 일단 크기는 같아야 하고, 복사된 부위 제외하고는 널이여야함
