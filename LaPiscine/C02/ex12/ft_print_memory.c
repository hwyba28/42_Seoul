#include <unistd.h>

void    ft_save_tobuff(int num, int max, int buff[], int index)
{
    if (num > max - 1)
        ft_save_tobuff(num / max, max, buff, index + 1);
    buff[index] = num % max;
}

void    ft_write_hex(unsigned int number, int radix, int count)
{
    int    buffer[15];
    int    index;

    index = -1;
    while (index++ < 14)
        buffer[index] = 0;
    ft_save_tobuff(number, radix, buffer, 0);
    index = -1;
    while (index++ < count)
        write(1, &"0123456789abcdefgh"[buffer[count - index]], 1);
}

void    ft_cant_write(char *c)
{
    if (*c > ' ' && *c < 127)
        write(1, c, 1);
    else
        write(1, &".", 1);
}

void    ft_print_memory_row(void *addr, unsigned int size, char *cr_addr)
{//사이즈 그냥 출력 크기??
    int index;

    ft_write_hex((unsigned int)*cr_addr, 16, 14);// 15개 문자 출력
    write(1, &": ", 2);
    index = 0;
    while (index++ < 16) // 16개 칸 - 한행
    {
        if (addr + size <= (void *)(cr_addr + index - 1)) //줄맞춤 (한 줄에서 남은 칸)
            write(1, &"  ", 2);
        else
            ft_write_hex((unsigned char)*(cr_addr + index - 1), 16, 1); //2개씩 출력
        
        if (index % 2 == 0) // 2개마다 공백
            write(1, &" ", 1);
    }
    index = 0;
    while (index++ < 16)//전체사이즈까지 출력불가능 문자는 .으로
        if (addr + size > (void *)(cr_addr + index - 1))
            ft_cant_write((char *)cr_addr + index - 1);
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    char    *cr_addr;

    cr_addr = (char *)addr;
    if (size != 0){
        while ((void *)cr_addr < (addr + size))
        {
            ft_print_memory_row(addr, size, cr_addr);
            write(1, &"\n", 1);
            cr_addr += 16;
        }
    }
    return (addr);
}

int main(void){
    ft_print_memory("sdfsdfsdf",10);
}
