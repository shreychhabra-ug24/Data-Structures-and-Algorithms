def bsort(A):
    for i in range(len(A)):
        swapped = False
        for j in range(0,len(A)-i-1):
            if A[j]>A[j+1]:
                temp = A[j]
                A[j] = A[j+1]
                A[j+1] = temp
                swapped = True
        if not swapped:
            break
    print(A)
L = [i for i in range(0,10000)]
bsort(L)