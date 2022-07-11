int	ft_str_is_printable(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 32) || (str[c] > 126))
			return (0);
		c++;
	}
	return (1);
}

//아스키 출력가능한 문자가 32~126
//아스키 = 규정된 변환 코드
