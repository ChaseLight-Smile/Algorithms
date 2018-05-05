def findMaxAndMinValue():
    #arr = [8, 10, 7, 16, 10, 3, 9, 7, 20, 2]
    arr = [9, 8, 7, 6, 5, 9, 3, 2, 1]
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

max , min = findMaxAndMinValue()
print ("max:",max)
print ("min:",min)
