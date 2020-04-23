## **数据结构与算法**
## **数据结构与算法**


### **1. 概述**
***

包括但不限于以下内容：

* **基本数据结构与算法**
  * **min-Heap/max-Heap**
  * **Union Find**
  * **Stack**
  * **queue**
  * **Binary Search**
  * **Trie**
  * **map/set**
  * **树（Trees）**
	  * **Binary Search Trees**
	  * **Binary Trees**
	  * **N-rray Trees**
	  * **Red-black Trees**
	  * **B-Trees**
	  * **B<sup>+</sup>-trees**
	  * **B<sup>\*</sup>-trees**
  * sort
	  * implementation quick sort
	  * implementation merge sort
	  * implementation heap sort
  * **Graph Algorithms**
* **算法设计技术**
	* **Dynamic Programming**
	* **Greedy methods**
	* **Recursive**
	* **Linear Programming**
	    * 我主要在调度研究中采用，但是通常调度中的问题都是NP-Hard，还得设计DP算法解决
* Machine Learning ALgorithms

### **2. 算法列表**
***

* insertSort(int[] arr);  完成插入排序过程
* insertSortRecurtion(int[] arr,int length); 插入排序递归算法
* sumBinarySystemNumber(int[] addNumber1,int[] addNumber2);   实现两个n位二进制数加法操作
* selectionSort(int[] arr);  完成选择排序过程
* bubbleSort(int[] arr); 完成冒泡排序
* merge(int[] num1,int[] num2); 合并两个已经排序好的数组
* findMedianSortedArrays(int[] nums1, int[] nums2);  LeetCode第四题，寻找两个已经排序好的数组的中位数，AC
* mergeSort(int[] arr , int start ,int end);  完成归并排序，在归并排序中使用了插入排序，利用了当数据规模很小时，插入排序优于归并排序，如何选择插入排序的最优元素个数是关键
* reverse(int x);  反转整数，LeetCode第七题，AC
* mergeTwoLists(ListNode l1, ListNode l2); 合并两个已经排序好的List，时间复杂度O(m+n)，LeetCode第22题，AC
* threeSum(int[] nums); LeetCode第15题，三个数的和，AC
* addRecursion(int[] nums, int length); 求任意多个数字和的递归算法
* hanoi(int n ,String A, String B, String C ); 汉诺塔问题的递归解法，只能使用递归解法
* trivialFindMaximumSubarray(int[] arr);   平凡的方法实现最大子数组问题，其时间复杂度为O(n^2)
* findMaximumSubarray(int[] arr,int start, int end);  寻找最大子数组问题，采用递归解法，时间复杂度为O(nlogn)，比平凡方法的时间复杂度低
* trivialSquareMatrixMultiply(int[][] nums1, int[][] nums2) 平凡方法实现矩阵乘法，时间复杂度为O(n^3)
* trivialSquareMatrixMultiplyRecursion(int[][] nums1, int[][] nums2 , int nums1RowStart, int nums1RowEnd,
			int nums1ColumnStart , int nums1ColumnEnd , int nums2RowStart , int nums2RowEnd , int nums2ColumnStart , int nums2ColumnEnd)  矩阵分块乘法，只使用与偶数维的情况，局限性很大
* removeElement(int[] nums, int val);  LeetCode第27题，该算法的时间复杂度为O(n)，AC
* sortList(ListNode head);  对链表使用归并排序，时间复杂度为O(nlogn)
* ZOJ1001Solution(); OJ1000题目解答，AC
* HDU1002Solution(); HDU1002题目解答，AC
* HDU1003Solution(); HDU1003题目解答，AC
* HDU1004Solution(); HDU1004题目解答，AC
* HDU1005Solution(); HDU1005题目解答，实现了普通递归算法，并将普通递归算法修改为尾递归算法，AC
* HDOJ1000();  AC
* HDOJ1001();  AC
* HDU1006(); tick and tick for the clock are roating every second and metting each other many times everyday.
* HDU1066();   Computing the factorical's last non-zero number. AC
* priorityqueue(int arr[],int length); priority queue is implenented by using maximum heap
* countingsort(int arr[], int length); counting sort. The time complexity of is linear time. It is not based on the comparsion.
* enhancingMethod(int arr[],int length);  find the maximum and minmum for enhancing method.The number of comparision decreases.
* sortASCII();   sort ASCII by using insertion sort.
* distance();   Computing the distance from node a(x1,y1) to b(x2,y2).
* volumn();   Computing the volumn of ball
* HDU2001()-HDU2017(); Practise the C++ language properties in HDUOJ page 11.  AC
* twoSum(int[] nums, int target);   LeetCode第一题，寻找一个数组中是否有两个数的和与指定的target数相同，AC
* addTwoNumbers(ListNode l1, ListNode l2);  LeetCode第二题，加两个数，AC
* maxSubSeqSum(int arr[], int length);  It is the most efficient method for the max sub sequence problem.
* isPalindrome(self, x)   Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward (Leetcode 9) AC
* romanToInt(string s)  Leetcode 13 AC
* LeetCode75.cpp Sort Colors AC
* LeetCode324.cpp Wiggle Sort II AC O(nlogn)
* LeetCode1046.cpp Last Stone Weight AC
* ListCode204.cpp Count Primes AC
* LeetCode1351.cpp Count Negative Numbers in a Sorted Matrix AC
* Leetcode3.cpp  Longest Substring Without Repeating Characters O(n) "slide window search"   AC
* Leetcode209.cpp  Minimum Size Subarray Sum "slide window search"  AC
* LeetCode76.cpp Minimum Window Substring   O(256n)  AC
* LeetCode1.cpp Two Sum AC
* LeetCode15.cpp 3Sum  two pointer   AC 
* LeetCode16.cpp 3Sum Closest AC
* LeetCode18.cpp 4Sum two pointer AC
* LeetCode8.cpp String to Integer (atoi) AC
* LeetCode509.cpp Fibonacci Number AC  
* LeetCode628.cpp Maximum Product of Three Numbers AC
* LeetCode26.cpp Remove Duplicates from Sorted Array AC
    * LeetCode80.cpp Remove Duplicates from Sorted Array II AC LeetCode26 follow-up
	* LeetCode83.cpp Remove Duplicates from Sorted List AC 
	* LeetCode82.cpp Remove Duplicates from Sorted List II AC
* sort
    * LeetCode912.cpp Sort an Array AC
	    * implement quicksort (最快，最省空间)
		* implement merge sort
		* implement heap sort
	* Cyclic Sort
		* LeetCode268.cpp Missing Number AC
		* LeetCode287.cpp Find the Duplicate Number AC
		* LeetCode448.cpp Find All Numbers Disappeared in an Array AC
		* LeetCode442.cpp Find All Duplicates in an Array AC
* Data Structure
    * map and set
        * LeetCode981.cpp Time Based Key-Value Store  unordered_multimap is time limited, but map is accepted
		* LeetCode287.cpp Find the Duplicate Number AC
		* LeetCode414.cpp Third Maximum Number unordered_map + priority_queue  O(n)  AC
		* LeetCode1089.cpp Duplicate Zeros AC
		* LeetCode239.cpp Sliding Window Maximum  AC  multiset
		* LeetCode480.cpp Sliding Window Median  AC multiset
		* LeetCode540.cpp Single Element in a Sorted Array AC
		* LeetCode350.cpp Intersection of Two Arrays II  Hashtable  O(n)  AC
		* **priority_queue and map/set can exchange at the solving min/max problem.**
		
	* Trie
	    * LeetCode208.cpp  Implement Trie (Prefix Tree) AC
        * LeetCode211.cpp Add and Search Word - Data structure design AC
	* priority_queue
	    * LeetCode658.cpp Find K Closest Elements AC
		* LeetCode703.cpp Kth Largest Element in a Stream AC
        * LeetCode973.cpp K Closest Points to Origin AC
		* LeetCode692.cpp Top K Frequent Words  AC
		* LeetCode347.cpp Top K Frequent Elements AC
		* LeetCode451.cpp Sort Characters By Frequency AC
		* LeetCode215.cpp Kth Largest Element in an Array O(n+k*logn)   AC
		* LeetCode414.cpp Third Maximum Number unordered_map + priority_queue  O(n)  AC
		* LeetCode378.cpp Kth Smallest Element in a Sorted Matrix   AC
		* LeetCode136.cpp Single Number AC hash table
		* LeetCode260.cpp Single Number III AC
		* LeetCode387.cpp First Unique Character in a String AC
		* LeetCode23.cpp Merge k Sorted Lists O(nlogk)   AC
	* linked list
	    * LeetCode66.cpp  Plus One AC
		* LeetCode148.cpp sort list AC
		* LeetCode206.cpp Reverse Linked List AC
		* LeetCode92.cpp Reverse Linked List II AC
		* LeetCode143.cpp Reorder List AC
		* LeetCode141.cpp Linked List Cycle AC
		* LeetCode142.cpp Linked List Cycle II AC
		* LeetCode876.cpp Middle of the Linked List AC
		* LeetCode203.cpp Remove Linked List Elements AC
		* LeetCode19.cpp Remove Nth Node From End of List O(2n) two pass algorithms   AC
		* LeetCode147.cpp Insertion Sort List AC
		* LeetCode445.cpp Add Two Numbers II AC
		* LeetCode83.cpp Remove Duplicates from Sorted List AC 
		    * LeetCode82.cpp Remove Duplicates from Sorted List II AC
	* deque
	* monotonous stack
	* queue
		* LeetCode102.cpp Binary Tree Level Order Traversal  AC
		* LeetCode107.cpp Binary Tree Level Order Traversal II AC
		* LeetCode637.cpp Average of Levels in Binary Tree AC
		* LeetCode429.cpp N-array Tree Level Order Traversal AC
		* all solutions **tree + queue** 
	* union find
		* LeetCode128.cpp Longest Consecutive Sequence  AC
		* LeetCodeUnionFind.cpp  LeetCode并查集模板，带路径压缩
* Binary Search
    * **LeetCode704.cpp Binary Search AC** (第一类最基本的二分检索题目)
	* **LeetCode33.cpp Search in Rotated Sorted Array AC(binary search)** 这四道题目其实延伸出很多题目，比如如何在Rotated Sorted Array中找到最小元素的下标并返回？**这里我向社区贡献了一道题目，供参考https://leetcode.com/contribute/18958**
		* **LeetCode81.cpp Search in Rotated Sorted Array II AC(binary search)**
		* **LeetCode153.cpp Find Minimum in Rotated Sorted Array AC (binary search)**
		* **LeetCode154.cpp Find Minimum in Rotated Sorted Array II AC(binary search)** (33 81 153 154解法完全一样，这是binary search的第二大类题型)
	* LeetCode69.cpp Sqrt(x) AC
	* LeetCode367.cpp Valid Perfect Square  AC
	* LeetCode278.cpp First Bad Version AC
	* LeetCode34.cpp Find First and Last Position of Element in Sorted Array AC
	* LeetCode374.cpp Guess Number Higher or Lower AC
	* **LeetCode162.cpp Find Peak Element AC**  (第三类二分检索题目)
	* LeetCode852.cpp Peak Index in a Mountain Array AC
	* **LeetCode287.cpp Find the Duplicate Number Binary Search AC  interesting problem** (第四类二分检索题目)
	* LeetCode35.cpp Search Insert Position AC
	* LeetCode744.cpp Find Smallest Letter Greater Than Target AC(binary search)
	* acwing63.cpp 数字在排序数组中出现的次数 AC  剑指offer题目
	* **LeetCode215.cpp Kth Largest Element in an Array binary search** O(n)时间复杂度 O(1)空间复杂度，比heap更省空间
	* **LeetCode378.cpp Kth Smallest Element in a Sorted Matrix   AC binary search 思路同LeetCode215.cpp**
	* LeetCode167.cpp Two Sum II - Input array is sorted binary search
	* LeetCode540.cpp Single Element in a Sorted Array  AC
	* LeetCode349.cpp Intersection of Two Arrays O(n)  AC
	* LeetCode74.cpp Search a 2D Matrix  AC nlogn
	* **LeetCode653.cpp Two Sum IV - Input is a BST AC  binary search** 树形结构二分
	* LeetCode108.cpp Convert Sorted Array to Binary Search Tree  AC  树形结构二分
		* LeetCode109.cpp Convert Sorted List to Binary Search Tree AC 
	* **LeetCode240.cpp Search a 2D Matrix II**  采用二分检索存在TLE，但是我认为采用二分，空间局部性最好，不存在行列无序检索的问题
	* **LeetCode230.cpp Kth Smallest Element in a BST AC (binary search & in-order traversal)**
	* **LeetCode719.cpp Find K-th Smallest Pair Distance   (单纯的使用binary search 或者 heap均 TLE Hard)，其中binary search的方法和leetcode 215思路一致** 
	* **LeetCode786.cpp K-th Smallest Prime Fraction (单纯的使用binary search 或者 heap均 TLE Hard)**
	* LeetCode658.cpp Find K Closest Elements AC
	* LeetCode275.cpp H-Index II
* BFS and DFS of Tree，including Binary Search Tree, Binary Tree and N-array Tree
    * LeetCode701.cpp Insert into a Binary Search Tree  AC
    * LeetCode102.cpp Binary Tree Level Order Traversal  AC
    * LeetCode107.cpp Binary Tree Level Order Traversal II AC
    * LeetCode637.cpp Average of Levels in Binary Tree AC
    * LeetCode429.cpp N-array Tree Level Order Traversal AC
    * LeetCode1305.cpp All Elements in Two Binary Search Trees AC
    * LeetCode1302.cpp Deepest Leaves Sum AC
	* LeetCode100.cpp Same Tree AC
	* LeetCode230.cpp Kth Smallest Element in a BST AC
	* LeetCode222.cpp Count Complete Tree Nodes AC
	* LeetCode104.cpp Maximum Depth of Binary Tree AC
    * LeetCode559.cpp Maximum Depth of N-ary Tree AC
	* LeetCode257.cpp Binary Tree Paths AC
	* LeetCode111.cpp Minimum Depth of Binary Tree AC
	* LeetCode112.cpp Path Sum AC
	* LeetCode113.cpp Path Sum II AC
	* LeetCode1161.cpp Maximum Level Sum of a Binary Tree AC
	* LeetCode965.cpp Univalued Binary Tree AC
	* LeetCode653.cpp Two Sum IV - Input is a BST AC
	* LeetCode513.cpp Find Bottom Left Tree Value AC
	* LeetCode515.cpp Find Largest Value in Each Tree Row AC
	* LeetCode129.cpp Sum Root to Leaf Numbers AC
	* leetCode103.cpp Binary Tree Zigzag Level Order Traversal AC
	* LeetCode938.cpp Range Sum of BST AC
	* LeetCode144.cpp Binary Tree Preorder Traversal AC
	* LeetCode145.cpp Binary Tree Postorder Traversal AC
	* LeetCode94.cpp Binary Tree Inorder Traversal AC
	* LeetCode173.cpp Binary Search Tree Iterator AC
	* LeetCode590.cpp N-array Tree Postorder Traversal AC
	* LeetCode589.cpp N-array Tree Preorder Traversal AC
	* LeetCode700.cpp Search in a Binary Search Tree AC
	* LeetCode110.cpp Balanced Binary Tree  AC
	* Construction Tree
		* LeetCode108.cpp Convert Sorted Array to Binary Search Tree  AC
			* LeetCode109.cpp Convert Sorted List to Binary Search Tree AC 
		* LeetCode1008.cpp Construct Binary Search Tree from Preorder Traversal AC
	* LeetCode1022.cpp Sum of Root To Leaf Binary Numbers
	* LeetCode127.cpp Word Ladder 双向BFS
	* LeetCode988.cpp Smallest String Starting From Leaf
	* LeetCode1376.cpp Time Needed to Inform All Employees
	* LeetCode124. Binary Tree Maximum Path Sum   LevelOrder + 最大连续子数组和  Hard
* BFS and DFS of Graph
    * LeetCodeGraphTraversalTemplate.cpp  图的DFS和BFS模板，保存图时采用了邻接列表的方式，不用邻接矩阵(浪费空间和时间)

### **3. 时空复杂度分析**
***

#### **3.1 理论**
***

写完算法后，通常情况下，我们需要对算法进行时空复杂度分析对比性能。有一种对比方法是将对比的算法放在同一台机器上运行统计时间，我们把这种方法称为“事后统计法“。但是这种方法存在明显的缺陷，当数据规模发生变化，或者运行在不同的处理器上时，算法的性能可能会存在较大的差异。因此，对于不同的算法，合理地给出算法运行的上下界很有必要。**在一个算法种，通常可以只分析算法种的循环、递归等部分。**空间复杂度分析相对于时间复杂度分析就要简单的多，只需要关注代码中最浪费存储的部分就可以了。

```C
 int cal(int n) {
   int sum = 0;
   int i = 1;
   for (; i <= n; ++i) {
     sum = sum + i;
   }
   return sum;
 }
```

如上述代码，在上述代码中，只有for循环中的`sum+=i`被执行了n次，其它代码的执行均与n无关。本例中，我们将算法的时间复杂度表示为O(n)，表示算法的执行时间与n成线性比例。在算法分析中，用大O表示时间复杂度，大O不是算法的真正执行时间，而是表示代码的执行时间随数据规模增长的变化趋势，所有我们也称为渐进时间复杂度。常见的时间复杂度包括：

$O(1) < O(lgn) < O(n) < O(nlogn) < O(n^2) < O(2^n) < O(n!)$ 其中，$O(2^n) < O(n!)$ 被称为$NP$难问题。<font color="red">为使得公式能够真长显示，请在chrome的扩展程序中，打开chrome网上应用店，然后搜索MathJax Plugin for Github，下载该插件，并且启用，就可以让上述公式正常显示。</font>

在时空复杂度分析中，有下面三个法则：

* 只关注循环执行次数最多的一段代码
* 加法法则：总复杂度等于量级最大的那段代码的复杂度，该法则适用于多段平行代码段，总的时间复杂度为最大
* 乘法法则：嵌套代码的复杂度等于嵌套内外代码复杂度的乘积

#### 3.2 最好，最坏、平均、时间复杂度分析
***

3.1节讲了基本的时间复杂度表示方法，本节将重点讲述最好、最坏、平均、均摊时间复杂度分析，这样便有了完整的时间复杂度分析方法。

```C
// n 表示数组 array 的长度
int find(int[] array, int n, int x) {
  int i = 0;
  int pos = -1;
  for (; i < n; ++i) {
    if (array[i] == x) pos = i;
  }
  return pos;
}
```

上述代码的时间复杂度为O(n)，代码性能较差，修改为下面部分：

```C
// n 表示数组 array 的长度
int find(int[] array, int n, int x) {
  int i = 0;
  int pos = -1;
  for (; i < n; ++i) {
    if (array[i] == x) {
       pos = i;
       break;
    }
  }
  return pos;
}
```

如上代码，在**最好情况下：数组的首元素的值与x相等，此时时间复杂度为O(1)，在最坏情况下：遍历整个数组，但是仍然没有找到对应的元素，此时的时间复杂度为O(n)。**至于平均时间复杂度的分析稍微复杂一些，**平均之间复杂度又称为期望时间复杂度或加权时间复杂度。**在本例中，有n个元素，每个元素都有$1/n$的可能性被选中，并且被选中的元素有$1/2$的可能性等于x，因此：

$1 * 1/(2n) + 2 * 1/(2n) + ... + n * 1/(2n) + n * 1/2= (3n+1)/4$ 

上述值就是每个位置可能出现等于x的情况的加权平均值，也叫做期望值，所以平均时间复杂度的全称应该叫做加权平均时间复杂度或者期望时间复杂度。上述值用大O表示为O(n)。另外一种分析方法是，总共有n+1种情况，n种情况下找到该元素，1种情况下元素不在数组中，如下：

$(1+2+...+n+n)/(n+1) = n(n+3)/(2(n+1))$

这种分析方法没有考虑每种情况出现的概率，不可取。

#### **3.3 均摊时间复杂度分析**
***

上述两节之后我们已经初步掌握了时间复杂度的分析方法，本节介绍均摊时间复杂度，均摊时间复杂度对应于算法中的摊还分析(或者叫平摊分析)。相比最好、最差、平均时间复杂度，均摊时间复杂度的使用场景更加特殊、更加有限。

```C
 // array 表示一个长度为 n 的数组
 // 代码中的 array.length 就等于 n
 int[] array = new int[n];
 int count = 0;
 
 void insert(int val) {
    if (count == array.length) {
       int sum = 0;
       for (int i = 0; i < array.length; ++i) {
          sum = sum + array[i];
       }
       array[0] = sum;
       count = 1;
    }

    array[count] = val;
    ++count;
 }
```

这段代码实现了往数组中插入数据的功能。当数组满了之后，也就是代码中 count==array.length时，通过for循环遍历数组求和，并清空数组，将求和之后的sum值放到数组的第一个位置，然后再将心得数据插入。当数组一开始有空闲位置时，则直接将数据插入数组。

**最好情况下时间复杂度**：O(1)，此时数组未满，并且由于count会自动执行加1操作，因此不用遍历找寻空位。

**最坏情况下时间复杂度**：O(n)，此时数组装满，首先需要遍历数组的全部元素执行累加操作，接着将累加后的和放入到数组的0位置上，然后count执行加1操作指向下一个位置，后续操作与最好情况下时间复杂度吻戏类似。

**平均时间复杂度**：假设数组的长度为n，根据插入的位置不同，可以将其分为n中情况，每种情况的时间复杂度都为O(1)，除此之外，还有一种当数组没有空闲位置时的情况，此时的时间复杂度为O(n)，而且这n+1中情况发生的概率一样，都是$1/(n+1)$，所以根据加权平均的计算方法，平均时间复杂度为：

$1 * 1/(n+1) + 1 * 1/(n+1)  ... + n * 1/(n+1)  = O(1)$

到目前位置，最好情况下时间复杂度、最坏情况下时间复杂度、平均情况下时间复杂度的计算，理解起来都没有任何问题。但是这个例子的平均复杂度分析其实并不需要上述那样复杂，不需要引入概率论的知识。这是为什么呢？其实将本例的insert()和前面的find()进行对比，可以知道，find()函数在极端情况下复杂度才为O(1)，但是insert在大部分情况下，时间复杂度都为O(1)，只有当数组没有空闲位置时，采薇O(n)。其次对于insert()，O(1)时间复杂度的插入和O(n)时间复杂度的插入，出现的频率是非常有规律的，而且有一定的前后时序关系，一般都是一个O(n)插入只有，紧跟着$n-1$个O(1)的插入操作，循环往复。所以针对这种特殊的场景，我们引入了一种更加简单的分析方法：摊还分析法，通过摊还分析得到的时间复杂度，本文给其命名为均摊时间复杂度。**那究竟如何使用摊还分析法来分析算法的均摊时间复杂度呢？**

我们还是继续看在数组中插入数据的例子。每一次O(n)的插入操作，都会跟着n-1次O(1)的插入操作，所以把时间耗时多的那次操作均摊到接下来的n-1次耗时少的操作上，均摊下来，这一组连续的操作的均摊时间复杂度就是O(1)，这就是均摊分析的大致思路。均摊时间复杂度和弹摊还分析的应用场景比较复杂，所以我们并不会经常用到。为了方便理解和记忆，本文总结了一下它们的应用场景。如果你以后遇到了，知道是怎么回事就行了。

对一个数据结构进行的操作中，大部分情况下时间复杂度都很低，只有个别情况下时间复杂度比较高，而且这些操作之间存在前后连贯的时序关系，这个时候，我们就可以将这一组操作放在一块儿分析，看是否能够将较高时间复杂度的那次操作的耗时平摊到其它时间复杂度较低的操作上。而且，在能够应用平摊时间复杂度的分析场景中，一般均摊时间复杂度就等于最好情况下的时间复杂度。

尽管许多数据结构和算法书籍都花了很大的力气来区分平均时间复杂度和均摊时间复杂度，但是其实我认为，均摊时间复杂度就是一种特殊的平均时间复杂度，我们没必要花太多的精力去区分它们。我们应该花时间去掌握它的分析方法，摊还分析法。至于分析出来的结果叫平均还是均摊，并不重要。



#### **3.4 总结**
***

之所以引入最好时间复杂度、最坏时间复杂度、平均时间复杂度、均摊时间复杂度这些概念，是因为很多算法，在不同的输入情况下，算法的时间复杂度不一样。在引入这些概念以后，我们能够更加全面的表示算法的时间复杂度。



```C
// 全局变量，大小为 10 的数组 array，长度 len，下标 i。
int array[] = new int[10]; 
int len = 10;
int i = 0;

// 往数组中添加一个元素
void add(int element) {
   if (i >= len) { // 数组空间不够了
     // 重新申请一个 2 倍大小的数组空间
     int new_array[] = new int[len*2];
     // 把原来 array 数组中的数据依次 copy 到 new_array
     for (int j = 0; j < len; ++j) {
       new_array[j] = array[j];
     }
     // new_array 复制给 array，array 现在大小就是 2 倍 len 了
     array = new_array;
     len = 2 * len;
   }
   // 将 element 放到下标为 i 的位置，下标 i 加一
   array[i] = element;
   ++i;
}
/*答案：
最好时间复杂度O(1)，最坏时间复杂度O(n)，平均时间复杂度O(1)，均摊时间复杂度为O(1)
假设数组的长度为n，当数组未满时，每次往数组中添加元素的时间复杂度都为O(1)，当数组满时，需要O(n)的操作进行复制，并且这两个操作具有严格的时序关系，因此可以将复制的操作摊还给前面n-1次操作中，最终得到的时间复杂度仍然为O(1)
平均时间复杂度计算：
1 * 1/(n+1) + 1 * 1/(n+1)  ... + n * 1/(n+1)  = O(1)
*/
```

### **参考文献**
***

* http://www.cs.cmu.edu/~anupamg/advalgos15/
* http://speech.ee.ntu.edu.tw/~tlkagk/courses_ML20.html
* http://erikdemaine.org/classes/
