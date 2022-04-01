arr = [10,9,8,7,6,5,4,3,2,1]

# Swap function
def swap(list, pos1, pos2):
    list[pos1], list[pos2] = list[pos2], list[pos1]

def insertionSort(arr):
    for i in range (1,len(arr)):
        for x in range(i, 0, -1):
            if(arr[x]<arr[x-1]):
                swap(arr,x,x-1)
            else:
                break


def merge(n,m):
    mid = (m + n) // 2
    L = arr[n:mid+1]
    R = arr[mid+1:m+1]

    i=j=k=0

    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            arr[n+k] = L[i]
            i += 1
        else:
            arr[n+k] = R[j]
            j += 1
        k += 1

    # Checking if any element was left
    while i < len(L):
        arr[n+k] = L[i]
        i += 1
        k += 1

    while j < len(R):
        arr[n+k] = R[j]
        j += 1
        k += 1


def mergeSort(n,m):
    if (m-n) <= 2:
        insertionSort(arr[n:m])

    elif (m-n) >= 1:
        # Mid of the array
        mid = (m+n)//2

        # First half
        mergeSort(n,mid)

        # Second half
        mergeSort(mid+1,m)

        merge(n,m)




mergeSort(0,len(arr)-1)
print(arr)

