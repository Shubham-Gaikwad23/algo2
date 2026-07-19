def reorder(arr):
    i = -1
    for j in range(len(arr)):
        print(i,j,arr)
        if arr[j]%2 == 0:
            arr[i+1], arr[j] = arr[j], arr[i+1]
            i += 1

arr = [1,2,3,4,5,6,7,8,9]
reorder(
    arr
)
print(arr)