def selsort(arr):
    n = len(arr)
    for i in range(0,n):      #iterating over the array to get our min element in steps
        min = i             #sets the min elt for each iteration
        for j in range(min+1,n): #iterating over the list after the min has been set
            if arr[j]<arr[min]:  #if the found element is smaller than the selected min
                min = j          #j now becomes the min element 
        arr[i], arr[min] = arr[min], arr[i]     #swap function that puts min at correct position
    print(arr)


L = [56,43,32,87,61,90,1,0,-276]
selsort(L)