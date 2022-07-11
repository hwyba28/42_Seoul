char *ft_strcapitalize(char *str)
{
    //salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
    //Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
    //맨첫글자가 소문자일때 또는 루프문자 앞이 알파벳이 아닐때 현재 문자는 대문자로 변경
    //단 숫자가 앞일땐 변하지 않음
    int c;
    int check;

    c = 0;
    check = 0;
    while (str[c] != '\0')
    {
        
        
        
        if (check == 0 && (str[c] >= 'a' && str[c] <= 'z'))
        {
            str[c] -= 'a' - 'A';
            check++;
        }
        else if (check > 0 && (str[c] >= 'A' && str[c] <= 'Z')) // 현재 앞이 소문자였는지 여부 && 그다음이 대문자이면 소문자로 바뀌어야함
            str[c] += 'a' - 'A';
        else if ((str[c] < '0') || (str[c] > '9' && str[c] < 'A') // 그외에 숫자 문자말고 다른 기호의 경우
                || (str[c] > 'Z' && str[c] < 'a') || (str[c] > 'z'))
            check = 0; // 그다음번에 다시 1번째 if문 검사를 해야함
        else
            check++;  //check=1로 줘서 두번째부터만 다시 확인하게
        c++;
    }
    
    
    
    
    
    return (str);

}
