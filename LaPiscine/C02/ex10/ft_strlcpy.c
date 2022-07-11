unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int count;
	unsigned int index;

	count = 0;
	index = 0;
	while (src[count] != '\0')
		count++;
    
    // 복사할 사이즈
	if (size != 0)
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
    }
    //d원래 사이즈만 성공했다는 의미로 반환
	return (count);
}
