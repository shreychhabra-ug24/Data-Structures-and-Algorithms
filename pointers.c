#include <stdio.h>
#include<stdlib.h>
//step by step pointers tutorial for beginners (and myself)!
//a variable that contains a variable address
//the address of the object is given by the unary operator &
//for example: p = &c;
//assigns addr of c to variable p, p points to c
//this is different from the * operator
//*accesses the object that the pointer points to

//find a simple example below


int main (void){   //void f(void) only means that the function void doesnt take parameters
    int x = 3, y = 99, a[69];   //good practice to declare variables in the same line in c

    int *ptr;   //declaring the pointer as a variable ptr

    ptr = &y;   //assigning address of y to ptr

    x = *ptr;   //x now has the value 99

    *ptr = 47;  //has no effect

    printf("x = %d", x);

    return 0;
}