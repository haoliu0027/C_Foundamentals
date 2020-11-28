#include <stdio.h>
/*
Union all variables share the same space, and everytime there will be one var being stored.
in the example it would be 4bytes. when we set a = 1 and get b value. they should have the 
same starting addr, namely low addr. we can know that if b == 1, means the low bytes stored 
in the low addr.
*/
int main(int argc, int* argv){
        union w{
                int a;
                char b;
        }c;
        c.a = 1;
        // small edbian true; big -> false
        if(c.b == 1) printf("small");
        else printf("big");
        return 0;
}