package com.uniplore.solution;

/**
 * 功能: 寻找二维数组中的局部最大值点，最简单的方法是扫描整个二维数组并比较其周边的元素，这种算法的时间复杂度是O(n^2)
 * 设二维数组有n行m列
 * 本段代码实现同样的功能，但是时间复杂度从O(n^2)降到了O(nlogm)，并且算法同时保证了正确性
 * 算法思想: 找到某一列的全局最大值，这个过程的时间复杂度是O(n)，该元素的位置为(i,j)，检查(i,j-1) (i,j) (i,j+1) ，看(i,j)是否为局部最大值，如果是
 * 则直接返回结果，如果不是，如果arr[i,j-1] > arr[i,j]，此时扫描左侧做递归，过程和上面的一样，否则扫描右侧
 * @author 朱君鹏
 *
 */
public class FindLocalPeakTwoVersion {
  
	//二维版本的寻找局部最大值代码也存在明显的错误，需要改正
	public static int findLocalPeakTwoVersion(int[][]arr ,int start,int end) { //这里的start指示的是列的起始位置和终止位置
		//算出数组的行长度和列长度
		int rowLength = arr.length;   //算出总共有多少行
		int columnLength = Integer.MIN_VALUE;
		if(rowLength == 0) {
			return Integer.MIN_VALUE;   //返回最小值，即根本不存在这样的点
		}else{
			columnLength = arr[0].length;   //算出列总共有多少个元素
			if (columnLength == 1) {
				return arr[0][0];
			}
		}
		
		//如果不满足上面的基本情况，则开始采用二分查询查找算法
		int mid = (start + end) /2 ;  //算出整个二维数组的中间列
		
		int max = arr[0][mid] ;  //假设max列列的局部最大值
		int iMax = 0;
		
		//在mid列找寻那一行会存在全局最大值，对于m×n矩阵，时间复杂度为O(m)
		for (int i = 0; i < rowLength ; i++) {
			if( max < arr[i][mid]){
				max = arr[i][mid];
				iMax = i;
			}else {
				continue;
			}
		}// for循环结束
		
		//递归结束条件
		if (iMax == 0 && mid == 0 && arr[iMax][mid] > arr[iMax][mid+1] ) {
			return max;   //返回最大值
		}
		
		//取到除第一列和最后一列的其它列
		if (iMax == 0 && mid != 0 && arr[iMax][mid] > arr[iMax][mid-1] &&  arr[iMax][mid] > arr[iMax][mid+1] ) {
			return max;   //返回最大值
		}
		
		//取到最后一列
		if (mid == columnLength-1  &&  arr[iMax][mid] > arr[iMax][mid-1]) {
			return max;
		}
		
		if (mid != 0 && arr[iMax][mid] < arr[iMax][mid-1]) {
			return findLocalPeakTwoVersion(arr, start, mid-1);
		}else {
			return findLocalPeakTwoVersion(arr, mid+1, end);
		}
	}
	public static void main(String[] args) {
		//int[][] arr = {{10,8,10,10},{14,13,12,11},{15,9,11,21},{16,17,19,20}};   //测试组1 
		//int[][] arr = {{10,8,10,10},{14,13,12,11},{15,9,11,10},{16,17,19,20}};  //测试组2
		//int[][] arr = {{1}};
		//int[][] arr = {};
		int[][] arr = {{}};
		//int[][] arr = {{1,2},{2,3}};
		if (arr.length != 0) {
			int columnLength = arr[0].length;   //算出列总共有多少个元素
			if (columnLength == 0) {
				System.out.println(findLocalPeakTwoVersion(arr, 0, 0));
			}
			System.out.println(findLocalPeakTwoVersion(arr, 0, columnLength-1));
		}else {
			System.out.println(findLocalPeakTwoVersion(arr, 0, 0));
		}
		
		
	}
}
