#include <stdio.h>

int main(void){
	int size = sizeof(void *);
	int size2 = sizeof(int *);
	long d = 9122533156456;
	char c = 'i';
	printf("9의 주소는 : %p\ni의 주소는 : %p\n", &d, &c);
	printf("void *의 크기 : %d\nint *의 크기 : %d\n", size, size2);
}
