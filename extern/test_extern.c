#include <stdio.h>
// gcc -o test_extern test_extern.c test_extern2.c
int main(int argc, int* argv){
        extern const int num;
        extern void func();
        func();
        printf("the number is %d\n", num);
        return 0;
}