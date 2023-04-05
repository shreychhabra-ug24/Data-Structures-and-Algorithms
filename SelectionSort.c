#include <stdio.h>

//func to swap 2 elements
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//selection sort algorithm
void selsort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int min = i;
        for(int j = min + 1; j<n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

//func to print array
void printarr(int arr[], int n){
    for (int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//main driver code
int main(){
    int L[] = {56,43,32,87,61,90,1,0,-276};
    int n = sizeof(L) / sizeof(L[0]);
    selsort(L,n);
    printarr(L,n);
}