# <Python代码：完成一组序列的插入排序,使得序列按照从小到大的顺序排列>
def insertionSort():
    # arr = [9,8,7,6,5,9,3,2,1]
    arr = [8, 10, 7, 16, 10, 3, 9, 7, 20, 2]  #给定的待排序序列
    arrLength = len(arr)   #求出数组的长度
    for i in range(1,arrLength):    #从第二个元素开始遍历，例子中也就是从10开始往后遍历
        min = arr[i]         # 假设最小值
        k = i;     #设置哨兵，用于监视真正最小值的正确位置
        for j in range(i-1,-1,-1):       #接着从[0,i-1]的位置上与min比较
            if min < arr[j]:             #如果min较小
                arr[j+1] = arr[j]        #arr[j] 向后走一个位置
                k = j                    #同时哨兵向前走一个位置
            else:
                break
        arr[k] = min    #循环结束将min放在正确的位置
    for i in range(0,arrLength,1):    #循环输出排序好的数组
        print (arr[i], end  = " ")
insertionSort()
print("\n")


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

#<Python代码：二分查找。对于排好序的序列，查找数列中是否存在某个数，如果存在，则返回该数所在的位置，如果不存在，返回-1000>
def binarySearch(arr, start, end, target):
    if start >= end  and target != arr[start]:
        result = -1000     #表示找不到对应的位置，我想用-1，但是Python中-1代表数列的最后一个位置
        return result
    middlePosition = (start+end)//2   #找到中间位置
    if target == arr[middlePosition]:
        result = middlePosition+1
        return result
    elif target > arr[middlePosition]:
        result = binarySearch(arr, middlePosition+1,end,target)
    elif target < arr[middlePosition]:
        result = binarySearch(arr,start,middlePosition-1,target)
    return result
arr = [-100,-23,-1,2,30,90,100]
result  = binarySearch(arr,0,len(arr)-1,-100)
print("二分查找的结果为:",result,end="\n")

#<Python代码：给定一个排好序的数字序列，插入一个数字在原数列的正确位置上，并且原数列的长度加1>
def insertElement(arr,element,arrLength):
    #顺序查找，时间复杂度为O(n)
    if element <= arr[0]:
        position = 0     #说明新插入的元素应该放在数组的0位置
        arr.insert(position, element)  #在0位置插入元素，使用Python中list自带的insert函数来实现
        return arrLength+1
    if element >= arr[len(arr)-1]:
        position = len(arr)      #将len(arr)存入R1寄存器中，说明新插入的元素应该放在数组的len(arr)位置
        arr.insert(position, element)
        return arrLength+1
    for i in range(0,arrLength-2,1):
        if arr[i] <= element and arr[i+1] >= element:  #找到了element的位置
            position = i+1     #说明新插入的元素应该放在i+1的位置
            print("position:",position)
            arr.insert(position, element)
            return arrLength+1
        else:
            continue
arr = [1, 2, 3, 4, 5, 6, 7, 8]
arrLength = len(arr)
arrLength = insertElement(arr,4,arrLength)
for i in range(0, arrLength, 1):
    print(arr[i], end=" ")
print("列表长度为:",arrLength)
print("\n")

#<Python代码：快速排序递归实现>
def quickSort(L):
    if len(L)<=1:
        return L
    Lleft = []
    Lright = []
    key = L[0]
    for i in L[1:]:
        if key < i:
            Lright.append(i)
        else:
            Lleft.append(i)
    return quickSort(Lleft) + [L[0]] +  quickSort(Lright)
arr = [8, 10, 7, 16, 10, 3, 9, 7, 20, 2]  #给定的待排序数组
result = quickSort(arr)
resultLength = len(result)
for i in range(0,resultLength,1):
    print(result[i],end=" ")
print("\n")


#<Python代码：拓扑排序算法>
def topological_sort(graph):
    is_visit = dict((node, False) for node in graph)
    li = []

    def dfs(graph, start_node):

        for end_node in graph[start_node]:
            if not is_visit[end_node]:
                is_visit[end_node] = True
                dfs(graph, end_node)
        li.append(start_node)

    for start_node in graph:
        if not is_visit[start_node]:
            is_visit[start_node] = True
            dfs(graph, start_node)

    li.reverse()
    return li


if __name__ == '__main__':
    graph = {
        'v1': ['v5'],
        'v2': ['v1'],
        'v3': ['v1', 'v5'],
        'v4': ['v2', 'v5'],
        'v5': [],
    }
    li = topological_sort(graph)
    print(li)


def isDays(year,month,day):
    months = [31,0,31,30,31,30,31,31,30,31,30,31]
    sum = 0
    if (year % 400 ==0) or (year % 100 !=0 and year % 4 == 0):
        months[1] = 29
    else:
        months[1] = 28

    for i in range(0,month-1,1):
        sum += months[i]

    sum += day
    print("days:",sum)

isDays(2018,5,5)   #125
#isDays(2006,3,12)  #71

def findMaxAndMinValue(arr):
    arrLength = len(arr)
    if arrLength % 2 == 0:
        if arr[0] >= arr[1]:
            max = arr[0]
            min = arr[1]
        else:
            max = arr[1]
            min = arr[0]
        for i in range(2,arrLength,2):
            if arr[i] > arr[i+1]:
                if arr[i] > max:
                    max = arr[i]
                if arr[i+1] < min:
                    min = arr[i+1]
            else:
                if arr[i+1]>max:
                    max = arr[i+1]
                if arr[i] < min:
                    min = arr[i]
        return max,min
    else:
        max = arr[0]
        min = arr[0]
        for i in range(1,arrLength,2):
            if arr[i] > arr[i+1]:
                if arr[i] > max:
                    max = arr[i]
                if arr[i+1] < min:
                    min = arr[i+1]
            else:
                if arr[i+1]>max:
                    max = arr[i+1]
                if arr[i] < min:
                    min = arr[i]
        return max,min
arr = [8, 10, 7, 16, 10, 3, 9, 7, 20, 2]
#arr = [9, 8, 7, 6, 5, 9, 3, 2, 1]
max , min = findMaxAndMinValue(arr)
print ("max:",max)
print ("min:",min)


#<Python代码：汉诺塔递归实现>
def hanoiTower(n, a, buffer, c):
    if(n == 1):
        print("结束时输出:",a,"->",c)
        return
    hanoiTower(n-1, a, c, buffer)
    hanoiTower(1, a, buffer, c)
    #print("中间输出：",a, "->", c)
    hanoiTower(n-1, buffer, a, c)
    return
hanoiTower(3, 1,2,3)


def revertInt(a):
    while a!=0:
        m = a%10
        print(m)
        a = a//10
revertInt(12345)


