#include "ft_printf.h"
#include <stdio.h>

int main(void){
	int a = -2147483648;
	unsigned int b = 3147483648;

	ft_printf("---------- ft_printf ----------\n");
	ft_printf("a의 포인터(%%p) : %p\n정수 a의 값 (%%d) : %d\n정수 a의 값 (%%i) : %i\n", &a, a, a);
	ft_printf("unsigned int b의 값 (%%u) : %u\nb의 16진수 값 (%%x) : %x\nb의 16진수 값 (%%X) : %X\n\n\n", b, b, b);
	
	printf("------------ printf ------------\n");
	printf("a의 포인터(%%p) : %p\n정수 a의 값 (%%d) : %d\n정수 a의 값 (%%i) : %i\n", &a, a, a);
	printf("unsigned int b의 값 (%%u) : %u\nb의 16진수 값 (%%x) : %x\nb의 16진수 값 (%%X) : %X\n", b, b, b);
}
