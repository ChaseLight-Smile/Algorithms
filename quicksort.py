def partitionHoareModify(arr, start, end):
    cursorLeft = start #set cursor for the left value
    cursorRight = end  #set cursor for the right value
    key = arr[start]  # set key value as standard
    while(True):
        while(arr[cursorLeft]<key):
            cursorLeft += 1
        while(arr[cursorRight]>key):
            cursorRight -=1
        if(cursorLeft < cursorRight):
            #swap the values
            temp = arr[cursorLeft]
            arr[cursorLeft] = arr[cursorRight]
            arr[cursorRight] = temp
        else:
            return cursorLeft

def quicksort(arr, start, end):

    if(start < end):
        position = partitionHoareModify(arr,start,end) #use partitionHoare is error because of do...while
        quicksort(arr,start,position-1)
        quicksort(arr,position+1,end)

L = [2,8,7,1,3,5,6,4]
quicksort(L,0,len(L)-1)
print L
