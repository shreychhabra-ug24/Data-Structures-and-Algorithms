#include <math.h>
#include <stdio.h>

void insort(int a[], int n){
    int i, cur;
    for(i=1; i<n; i++){
        cur = a[i];

        while(i>0 && a[i-1] > cur){
            a[i] = a[i-1];
            i = i-1;
        a[i] = cur;
        }
    }
}

void print(int a[], int n){
    int i;
    for ( i = 0; i<n; i++){
        printf("%d", a[i]);
    printf("\n");
    }
}

int main(){
    int L[]= {12, 6, 10, 8, 20};
    int n = sizeof(L) / sizeof(L[0]);
    insort(L, n);
    print(L, n);
    return 0;
}