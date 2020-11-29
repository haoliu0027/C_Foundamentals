#include <stdio.h>
#include <stdlib.h>

typedef void(*action)(int c);
void skip(int c), print(int c);

typedef enum State{Before, Inside, After, num_states} states;
typedef enum Action{Space, Newline, Other, num_actions} actions;
typedef struct Edge{states next; action act}edges;

edges lookup[num_states][num_actions] = {
        {{Before, skip}, {Before, print}, {Inside, print}},
        { {After, skip}, {Before,print}, {Inside,print} },
        { {After, skip}, {Before,print}, {After, skip} }
};

int main(){
        int c;
        states state = Before;
        while ( (c = getchar()) != EOF){
                actions in = (c == ' ' ? Space: (c == '\n' ? Newline : Other));
                edges *edge = &lookup[state][in];
                edge->act(c);
                state = edge->next; 
        }
        return 0;
}