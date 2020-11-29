#include <stdio.h>
#include <ctype.h>



typedef void (*action)(int c);
void skip(int c){}
void print(int c) {putchar(c);}

// typedef void (*voidfp)();
// typedef voidfp (*action)(int c);
// voidfp skip(int c), print(int c);


typedef enum State{ before, inside, after, num_states}states;
typedef enum Input{space, newline, other, num_inputs}input;
typedef struct {states next; action act;} edges;

edges lookup[num_states][num_inputs] = {
        { {before, skip}, {before, print}, {inside, print}},
        { {after, skip}, {before, print}, {inside, print}},
        { {after, skip}, {before, print}, {after, skip}}
};

int main(){
        int c;
        states state = before;
        while( (c = getchar()) != EOF){
                input inp = c == ' '? space : c == '\n' ? newline : other;
                edges *edge = &lookup[state][inp];
                edge->act(c);
                state = edge->next;
        }
        return 0;
}