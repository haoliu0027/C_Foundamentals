#include <stdio.h>

typedef void(*voidfp)(void);
typedef voidfp (*statefp)(int c);

voidfp before(int c), inside(int c), after(int c);



voidfp before(int c){
        if(c == ' ') ;
        else if (c == '\n')    putchar(c);
        else {
                putchar(c);
                return (voidfp)inside;
        }
        return (voidfp)before;
}

voidfp inside(int c){
        if(c == ' ') return (voidfp)after;
        else if (c == '\n'){
                putchar(c);
                return (voidfp)before;
        }else   {
                putchar(c);
                return (voidfp)inside;        
        }        
}

voidfp after(int c){
        if(c == '\n'){
                putchar(c);
                return (voidfp)before;
        }
        return (voidfp) after;        
}

int main(){
        int c;
        statefp state = before;
        while( (c = getchar()) != EOF ){
                state = (statefp)(*state)(c);
        }
        return 0;
}