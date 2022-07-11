char *ft_strcpy(char *dest, char *src){
//    dest = src; //얕은 복사라면 이 원리 가능
//but ft_strcpy가 깊은 복사이므로,
    int count = 0;
    while ( src != '\0'){
        dest[count]  = src[count];
        count++;
    }
    dest[count] = '\0';
    return dest;
}

//*포인터 = 값
