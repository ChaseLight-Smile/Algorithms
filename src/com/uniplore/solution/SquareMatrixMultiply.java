package com.uniplore.solution;
import org.junit.Test;

/**
 * 功能: 使用数组模拟矩阵，但是实际上这样做的效率极其低下，程序主要目的是实现矩阵的乘法，并且尽可能的减小算法的时间复杂度
 * @author 朱君鹏
 *
 */
public class SquareMatrixMultiply {
	
	//平凡方法求解矩阵乘法，时间复杂度为O(n^3)
	public static int[][] trivialSquareMatrixMultiply(int[][] nums1, int[][] nums2){
		int nums1RowLength = nums1.length;  
		//System.out.println(nums1RowLength);
		int nums1ColumnLength = nums1[0].length;
		//System.out.println(nums1ColumnLength);
        int nums2RowLength = nums2.length;
        //System.out.println(nums2RowLength);
        int nums2ColumnLength = nums2[0].length;
        //System.out.println(nums2ColumnLength);
        if(nums1ColumnLength != nums2RowLength) {
        	System.out.println("矩阵不能做乘法，矩阵乘法要求第一个矩阵的列数等于第二个矩阵的行数");
        	return null;
        }else {
			int[][] result = new int[nums1RowLength][nums2ColumnLength];
			for(int i = 0 ; i < nums1RowLength; i++){    //标记行
				for(int j = 0 ; j < nums2ColumnLength; j++) {   //标记列
				    int temp = 0 ;
					for(int k = 0 ; k < nums1ColumnLength ; k++) {
						temp = temp + nums1[i][k] * nums2[k][j];
					}
					result[i][j] = temp;
				}
			}
			return result;
		}
	}
	
	
	@Test
	public void testTrivialSquareMatrixMultiply() throws Exception {
		int[][] nums1 = {{1,2,3},{3,4,5},{6,7,8}};
		int[][] nums2 = {{1},{1},{1}};
		int[][] result = trivialSquareMatrixMultiply(nums1, nums2);
		for (int[] is : result) {
			for (int i : is) {
				System.out.print(i + " ");
			}
		}
	}
}
