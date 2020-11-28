/* 
Coding Assignment:  Reading a text from the standard input stream, line by line, 
and prints the first word of each line. Words are delimited by spaces.
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
        enum states {before, inside, after}state;
        int c;
        state = before;
        /*
        link for int getchar(void):
        https://www.runoob.com/cprogramming/c-function-getchar.html
        */
        while((c = getchar()) != EOF){
                switch (state){
                case before:
                        if(c == ' ') ;
                        else if (c == '\n')    putchar(c);
                        else {
                                putchar(c);
                                state = inside;
                        }
                        break;
                case inside:
                        if(c == ' ') state = after;
                        else if (c == '\n'){
                                state = before;
                                putchar(c);
                        }else   putchar(c);
                        break;
                case after:
                        if(c == '\n'){
                                putchar(c);
                                state = before;
                        }
                        break;
                default:
                        fprintf(stderr, "unknown state %d\n", state);
                        abort();
                }
        }
}