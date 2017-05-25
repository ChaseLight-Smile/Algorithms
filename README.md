### **Algorithms**
　　学习算法的记录，每个实现的算法都会详细的分析算法的时间复杂度，并证明算法的正确性，所涉及到的算法可能都会是百行级别的代码，
在这些代码中，主要是很对某种特殊的情况编码，没有使用泛型，甚至没有更加详细的讨论其它类型(多数为整型实现)，主要侧重实现某一种具体的算法思想。

#### **List of Implementation Algorithms**
***

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
* mergeSort(int[] arr , int start ,int end);  完成归并排序
* twoSum(int[] nums, int target); LeetCode第一题
* reverse(int x);  反转整数，LeetCode第七题
* mergeTwoLists(ListNode l1, ListNode l2); 合并两个已经排序好的List，时间复杂度O(m+n)，LeetCode第22题
* threeSum(int[] nums); LeetCode第15题，三个数的和
* addrRecursion(int[] nums, int length); 求任意多个数字和的递归算法
