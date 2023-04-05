#include <math.h>
#include <stdio.h>

void bsort(int a[], int n){
    int i, j,temp;
    for(i=0; i<n-1; ++i){
        for(j = 0; j<n-i-1; ++j){
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

            }
        }
    }
}

void print(int a[], int n){
    int i;
    for ( i = 0; i<n; ++i){
        printf("%d", a[i]);
    printf("\n");
    }
}

int main(){
    int L[] = {78,432,37,6,0,9};
    int n = sizeof(L)/sizeof(L[0]);
    bsort(L,n);
    print(L,n);
    return 0;
}