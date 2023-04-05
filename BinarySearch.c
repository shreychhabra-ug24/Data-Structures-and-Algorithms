#include <stdio.h>
#include <stdlib.h>

//this is a recursive program 
//similar to my implementation in python

int binsearch(int data[], int target, int low, int high){
    int mid = (low+high)/2;
    if(low>high){
        return -1;
    }
    else{
        if (target == data[mid]){
            return mid;
        }
        else if(target<data[mid]){
            return binsearch(data, target, low, mid-1);
        }
        else{
            return binsearch(data, target, mid+1, high);
        }
    }

}

int main(){
    int arr[10000]; //creates an array of 10000 elements that we use to test out function
    int i;
    for (i=0;i<10000; i++){
        arr[i] = i+1;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Enter an element to search for in the list: ");
    scanf("%d", &target);
    int result = binsearch(arr, target, 0, n-1);
    if(result !=-1){
        printf("Element present in array at index %d.", result);
    }
    else{
        printf("Element not present in array. ");
    }
    return 0;
}