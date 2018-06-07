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
result  = binarySearch(arr,0,len(arr)-1,100)
print("二分查找的结果为:",result)
print("\n")
