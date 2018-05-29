#<Python代码：给定一个排好序的数字序列，插入一个数字在原数列的正确位置上，并且原数列的长度加1>
def insertElement(element):
    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    arrLength = len(arr)
    #顺序查找，时间复杂度为O(n)
    if element < arr[0]:
        position = 0     #说明新插入的元素应该放在数组的0位置
        arr.insert(position, element)  #在0位置插入元素，使用Python中list自带的insert函数来实现
        return arr
    if element > arr[len(arr)-1]:
        position = len(arr)      #将len(arr)存入R1寄存器中，说明新插入的元素应该放在数组的len(arr)位置
        arr.insert(position, element)
        return arr
    for i in range(0,arrLength-2):
        if arr[i] <= element and arr[i+1] >= element:  #找到了element的位置
            position = i+1     #说明新插入的元素应该放在i+1的位置
            arr.insert(position, element)
            return arr
        else:
            continue
#arr = insertElement(7)
#arr = insertElement(0)
arr = insertElement(9)
arrLength = len(arr)
for i in range(0, arrLength, 1):
    print(arr[i], end=" ")
print("\n")
