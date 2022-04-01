arr = []

for i in range(100,0,-1):
    arr.append(i)


def insertionSort(n,m):
    for i in range (n,m):
        for x in range(i, n, -1):
            if(arr[x]<arr[x-1]):
                arr[x], arr[x-1] = arr[x-1], arr[x]
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
    if (m-n) < 3:
        insertionSort(n,m+1)

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

