#<程序：二分递归实现多项式乘法>
def multiply_poly(L1,L2):
    result=[]
    if len(L1) > len(L2):
        L1 , L2= L2 , L1
    if len(L1) == 1 and len(L2) != 1:
        for i in range(len(L2)):
            temp =[L1[0][0]+L2[i][0], L1[0][1]*L2[i][1]]
            result.append(temp)
        return result
    if len(L1) != 1 and len(L2) != 1:
        mid = len(L2)//2
        leftL2 = L2[0:mid]
        rightL2 = L2[mid:len(L2)]
        resultleftL2 = multiply_poly(leftL2, L1)
        resultright2 = multiply_poly(rightL2, L1)
        result = resultleftL2 + resultright2   #这里应该包含合并同类项的代码
        return result
if __name__ == "__main__":
    L1=[[1,1],[6,5]]
    L2=[[2,1],[1,1],[0,2]]
    print(multiply_poly(L1,L2))
