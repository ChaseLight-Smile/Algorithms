# <Python代码：完成一组序列的插入排序,使得序列按照从小到大的顺序排列>
def insertionSort():
    # arr = [9,8,7,6,5,9,3,2,1]
    arr = [8, 10, 7, 16, 10, 3, 9, 7, 20, 2]  #给定的待排序数组
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
