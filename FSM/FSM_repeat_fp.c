#include <stdio.h>
#include <stdlib.h>
void (*state)(int c); // global function ptr variable
void before(int c), inside(int c), after(int c);

void before(int c) {
    if(c != ' ') {
        putchar(c);
        if(c != '\n')
            state = inside;
    }
}

void inside(int c) {
    if(c != ' ')
        putchar(c);
    else {
        if(c == '\n') {
            putchar('\n');
            state = before;
        } else
            state = after;
    }
}

void after(int c) {
    if(c == '\n') {
        putchar('\n');
        state = before;
    }
} 

int main(){
        int c;
        state = before;
        while( (c = getchar()) != EOF){
                (*state)(c);
        }
        return 0;
}