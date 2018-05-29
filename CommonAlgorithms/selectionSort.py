#<Python代码：完成一组序列的选择排序，使得序列按照从小到大的顺序排列>
def selectionSort():
    #arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]
    arr = [8,10,7,16,10,3,9,7,20,2]
    arrLength = len(arr)
    for i in range(0,arrLength,1):
        min = arr[i]
        for j in range(i+1,arrLength,1):
            if min > arr[j]:
                min,arr[j] = arr[j],min   #交换两个数
            else:
                continue
        arr[i] = min
    for i in range(0, arrLength, 1):
        print(arr[i], end=" ")
selectionSort()
print("\n")
