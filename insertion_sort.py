#start with 1st element, consider it sorted
#move to next element, if smaller than 1st, then swap
#on reaching 3rd element, swap leftwards till it reaches its proper place
#worst case: O(n^2), best case O(n)

def insort(A):
    for k in range(1,len(A)):
        cur = A[k]                  #current element to be inserted
        #j = k                       #correct index k where A[k] is supposed to be
        while k>0 and A[k-1]>cur:   #as long as k-1 is greater than the current elt, execute
            A[k] = A[k-1]
            k = k-1
        A[k] = cur
    print(A)

L = [74,3,5,29,6,8,41,2,6,54,432,654]
insort(L)
