#<Python代码：递归实现最大值与最小值>
def findMaxAndValueRecursive(arr,start,end):
    if end == start+1:
        if arr[start] >= arr[end]:
            return arr[start],arr[end]
        else:
            return arr[end],arr[start]

    if end == start:
        return arr[start],arr[end]

    middle = (start+end)//2
    lmax, lmin = findMaxAndValueRecursive(arr,start,middle)
    rmax, rmin = findMaxAndValueRecursive(arr,middle,end)

    # merge the results
    if lmax >= rmax:
        max = lmax
    else:
        max = rmax

    if lmin <= rmin:
        min = lmin
    else:
        min = rmin
    return max,min

arr = [13,19,9,5,12,8,7,4,11,2,6,21]
length = len(arr)
max, min = findMaxAndValueRecursive(arr,0,length-1)
print ("Max:", max)
print ("Min:", min)

