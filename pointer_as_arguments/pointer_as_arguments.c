#include <stdlib.h>
#include <stdio.h>

/*
even if only return (&x); x is also the local variable in the sub fn.
In this case, there will be two ways:
1. transfer the pointer as arguements to the sub fn
2. declare a static variable in the sub fn, return addr
*/
int* foo(char* x){
	static char y = 'a';
	return (x);
}

int main(){
	char x = 'b';
	int *p = malloc(sizeof(char));
	p = foo(&x);
	printf("the address is: %p\n",p);
	printf("the value is: %c\n",*p);
	free(p);
	return 0;
}
