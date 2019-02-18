class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        else:
            listResult = []
            while x != 0:
                listResult.append(x % 10)
                x = x / 10
            size = len(listResult)
            for i in range(size):
                if (listResult[i] != listResult[size-1-i]):
                    return False
            return True