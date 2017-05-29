#### **算法列表**
***

* linearSearchRecursion(int[] arr,int search,int target); 线性查找的递归算法
* linearSearch(int[] arr,int target); 线性查找的非递归算法
* findMaxValue(int[] arr); 寻找一个数组中的全局最大值
* findLocalPeakOneVersion(int[] arr, int start, int end);  寻找数组中的局部最大值点，适合于一维数组
* findLocalPeakTwoVersion(int[] arr, int start, int end);  寻找数组中的局部最大值点，适合于二维数组
* insertSort(int[] arr);  完成插入排序过程
* insertSortRecurtion(int[] arr,int length); 插入排序递归算法
* binarySearch(int[] arr, int start, int end,int target);  完成二分搜索过程，使用了插入排序算法对原数组进行排序
* sumBinarySystemNumber(int[] addNumber1,int[] addNumber2);   实现两个n位二进制数加法操作
* selectionSort(int[] arr);  完成选择排序过程
* bubbleSort(int[] arr); 完成冒泡排序
* twoSum(int[] nums, int target);   LeetCode第一题，寻找一个数组中是否有两个数的和与指定的target数相同
* addTwoNumbers(ListNode l1, ListNode l2);  LeetCode第二题，加两个数
* merge(int[] num1,int[] num2); 合并两个已经排序好的数组
* findMedianSortedArrays(int[] nums1, int[] nums2);  LeetCode第四题，寻找两个已经排序好的数组的中位数
* mergeSort(int[] arr , int start ,int end);  完成归并排序，在归并排序中使用了插入排序，利用了当数据规模很小时，插入排序优于归并排序，如何选择插入排序的最优元素个数是关键
* twoSum(int[] nums, int target); LeetCode第一题
* reverse(int x);  反转整数，LeetCode第七题
* mergeTwoLists(ListNode l1, ListNode l2); 合并两个已经排序好的List，时间复杂度O(m+n)，LeetCode第22题
* threeSum(int[] nums); LeetCode第15题，三个数的和
* addRecursion(int[] nums, int length); 求任意多个数字和的递归算法
* hanoi(int n ,String A, String B, String C ); 汉诺塔问题的递归解法，只能使用递归解法
* trivialFindMaximumSubarray(int[] arr);   平凡的方法实现最大子数组问题，其时间复杂度为O(n^2)
* findMaximumSubarray(int[] arr,int start, int end);  寻找最大子数组问题，采用递归解法，时间复杂度为O(nlogn)，比平凡方法的时间复杂度低
* trivialSquareMatrixMultiply(int[][] nums1, int[][] nums2) 平凡方法实现矩阵乘法，时间复杂度为O(n^3)
* trivialSquareMatrixMultiplyRecursion(int[][] nums1, int[][] nums2 , int nums1RowStart, int nums1RowEnd,
			int nums1ColumnStart , int nums1ColumnEnd , int nums2RowStart , int nums2RowEnd , int nums2ColumnStart , int nums2ColumnEnd)  矩阵分块乘法，只使用与偶数维的情况，局限性很大
* searchMatrix(int[][] matrix, int target);  检索矩阵，LeetCode第74题
#### **说明**
***

　　很多算法都实现了递归版本和非递归版本，推荐使用非递归版本，因为递归很耗费空间，每一次递归都要开辟一个新的栈空间。
