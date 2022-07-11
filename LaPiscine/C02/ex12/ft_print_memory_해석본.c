#include <unistd.h>

//들어온 숫자 문자로 쪼개기
void    ft_write_tochar(int num, int radix, int buf[], int index)
{
    if (num > radix - 1)
        ft_write_tochar(num / radix, radix, buf, index + 1);
    buf[index] = num % radix;
}

void    ft_write_first_char_tohex(unsigned int num, int radix, int count)
{
    int    buffer[15]; // 첫번째 문자는 따로 출력 / 각 행에는 16개의 문자만 출력이므로 나머지 15문자 출력
    int    index;

    index = -1;
    while (index++ < 14)
        buffer[index] = 0;
    //16칸 초기화
    
    ft_write_tochar(num, radix, buffer, 0);

    index = -1;
    while (index++ < count)
        write(1, &"0123456789abcdefgh"[buffer[count - index]], 1); // 첫번째 항 다 출력 16개 문자(숫자)로 바뀐 16비트 주소(한 문자)
}

//출력할 수 없는 문자열의 경우 점으로 대체
void    ft_cant_write(char *c)
{
    if (*c > ' ' && *c < 127)
        write(1, c, 1);
    else
        write(1, &".", 1);
}

//각 행 메모리 출력
void    ft_print_memory_row(void *first_addr, unsigned int size, char *cr_addr)
{
    int index;
    //첫번째 문자 16진수
    ft_write_first_char_tohex((unsigned int *)cr_addr, 16, 14); //출력가능한 문자로 ->unsigned int
    write(1, &": ", 2);
    index = 0;
    while (index++ < 16)
    {
        if (first_addr + size <= (void *)(cr_addr + index - 1)) // 비교하기 위해 형 맞추기
            write(1, &"  ", 2);
        else // 첫번째 문자이면
            
            ft_write_first_char_tohex((unsigned char *)(cr_addr + index - 1), 16, 1);
        if (index % 2 == 0)
            write(1, &" ", 1);
    }
    index = 0;
    while (index++ < 16)
        if (first_addr + size > (void *)(cr_addr + index - 1))
            ft_cant_write((char *)cr_addr + index - 1);
}

//32비트 컴퓨터 주소 4바이트
/*
 32 Bit 프로그램을 예로 들어보자. 32 Bit의 경우 표현하여 사용 가능한 메모리양은 4,294,967,296 경우의 수이므로, OS에서 총 가용할 수 있는 메모리는 4 GB(4,294,967,296 Byte)가 된다. 32 Bit에서 포인터가 4 Byte인 이유는 여기서 분명해진다. 가용할 수 있는 모든 메모리의 경우의 수를 표현하기 위해서는 4 Byte 크기의 자료형이어야 때문이다.

 출처: https://programist.tistory.com/entry/C-언어-모든-포인터-변수-자료형이-똑같은-크기를-가지는-이유 [Programist's Laboratory]
 */
void    *ft_print_memory(void *addr, unsigned int size)
{
    char    *cr_addr;

    cr_addr = (char *)addr;
    while ((void *)cr_addr < (addr + size)) // 첫번째 주소 포인터부터 사이즈 범위까지
    {
        ft_print_memory_row(addr, size, cr_addr);
        write(1, &"\n", 1);
        cr_addr += 16;
    }
    return (addr);
}

int main (void){
    ft_print_memory("123135dfsdf",15);
}
