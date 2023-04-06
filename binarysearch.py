#mid is the median candidate to which target is compared
#we maintain 2 parameters, low and high


def bin_search(data, target, low, high):
    
    if low>high: 
        return -1 #element not present in array
    else:
        mid = (low+high)//2
        if target == data[mid]:
            return mid
        elif target < data[mid]:
            return bin_search(data, target, low, mid-1)
        else:
            return bin_search(data, target, mid+1, high)

arr = [i for i in range(0,10000)]

target = int(input("Enter element to search for in list: "))

res = bin_search(arr, target, 0, len(arr)-1)

if res != -1:
    print("Element is present at index", str(res))
else:
    print("Element is not present in array")