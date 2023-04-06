import random

#a recursive, divide and conquer algorithm
#consider an array A[p...r]
#we split the array from the middle into A[p...q] and A[q+1...r] & sort
#repeat until base case is reached
#merge the sorted arrays

def merge(A=[]):
    if len(A)>1:
        mid = len(A)//2     #middle element
        left = A[:mid]      #array to the left of mid   
        right = A[mid:]     #array to the right of mid
        merge(left)
        merge(right)
        i=j=k=0

        while i<len(left) and j<len(right):
            if left[i]<=right[j]:
                A[k] = left[i]
                i+=1
            else: 
                A[k] = right[j]
                j+=1
            k+=1
        while i<len(left):
            A[k] = left[i]
            i+=1
            k+=1
        while j<len(right):
            A[k] = right[j]
            j+=1
            k+=1
    return A


#random module to create a random array of 1000 numbers

A = [i for i in range(1000)]
random.shuffle(A)
print("Unsorted random array: ", A)
merge(A)
print("Array sorted with mergesort: ", A)
