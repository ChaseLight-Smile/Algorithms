package solution;
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
	
	//递归实现矩阵乘法，时间复杂度仍然为O(n^3)，将矩阵切割为分块矩阵，最后的计算结果取决于你怎么对矩阵进行分割，但是跨越确定的是，
	//对于A*B，则A中列的分割方式和B中行的分割方式必须是一样的，A的行和B的列自由的进行切割，在该段代码中我只考虑如下一种情况:
	//首先A和B都是n*n方阵，并且对A和B进行切割，切割成4块进行运算，下面的这段代码是适用于行列相等且为偶数的情况
	public static int[][] trivialSquareMatrixMultiplyRecursion(int[][] nums1, int[][] nums2 , int nums1RowStart, int nums1RowEnd,
			int nums1ColumnStart , int nums1ColumnEnd , int nums2RowStart , int nums2RowEnd , int nums2ColumnStart , int nums2ColumnEnd){
		int[][] result = {};
		
		if(nums1RowStart == nums1RowEnd && nums1ColumnStart == nums1ColumnEnd && nums2RowStart == nums2RowEnd && nums2ColumnStart == nums2ColumnEnd){
			//满足该条件，说明此时矩阵只包含一个元素
			result = new int[1][1];
			result[0][0] = nums1[nums1RowEnd][nums1ColumnEnd] * nums2[nums2RowEnd][nums2ColumnEnd];
			return result;
		}else {
			int nums1RowMid = (nums1RowStart + nums1RowEnd) / 2;   //标记nums1数组的行中点位置
			int nums1ColumnMid = (nums1ColumnStart + nums1ColumnEnd) / 2;   //标记nums1数组的列中点位置
			
			int nums2RowMid = (nums2RowStart + nums2RowEnd) / 2;  //标记nums2数组的行中点位置
			int nums2ColumnMid = (nums2ColumnStart + nums2ColumnEnd) / 2;  //标记nums2数组的列中点位置
			//否则使用分块矩阵乘法递归的实现
			int[][] topLeft1 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowStart, nums1RowMid, nums1ColumnStart, nums1ColumnMid, nums2RowStart, nums2RowMid, nums2ColumnStart, nums2ColumnMid);
		    int[][] topLeft2 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowStart, nums1RowMid, nums1ColumnMid+1, nums1ColumnEnd, nums2RowMid+1, nums2RowEnd, nums2ColumnStart, nums2ColumnMid);
		    
		    int[][] topLeft = new int[topLeft1.length][topLeft2[0].length];   //合并第一个部分
		    for (int i = 0; i < topLeft1.length; i++) {
				for (int j = 0; j < topLeft2[0].length; j++) {
					topLeft[i][j] = topLeft1[i][j] + topLeft2[i][j]; 
				}
			}
		    
		    int[][] topRight1 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowStart, nums1RowMid, nums1ColumnStart, nums1ColumnMid, nums2RowStart, nums2RowMid, nums2ColumnMid+1, nums2ColumnEnd);
		    int[][] topRight2 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowStart, nums1RowMid, nums1ColumnMid+1, nums1ColumnEnd, nums2RowMid+1, nums2RowEnd, nums2ColumnMid+1, nums2ColumnEnd);
		    
		    int[][] topRight = new int[topRight1.length][topRight2[0].length];   //合并第一个部分
		    for (int i = 0; i < topRight1.length; i++) {
				for (int j = 0; j < topRight2[0].length; j++) {
					topRight[i][j] = topRight1[i][j] + topRight2[i][j]; 
				}
			}
		    
		    int[][] bottomLeft1 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowMid+1, nums1RowEnd, nums1ColumnStart, nums1ColumnMid, nums2RowStart, nums2RowMid, nums2ColumnStart, nums2ColumnMid);
		    int[][] bottomLeft2 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowMid+1, nums1RowEnd, nums1ColumnMid+1, nums1ColumnEnd, nums2RowMid+1, nums2RowEnd, nums2ColumnStart, nums2ColumnMid);
		    
		    int[][] bottomLeft = new int[bottomLeft1.length][bottomLeft2[0].length];   //合并第一个部分
		    for (int i = 0; i < bottomLeft1.length; i++) {
				for (int j = 0; j < bottomLeft2[0].length; j++) {
					bottomLeft[i][j] = bottomLeft1[i][j] + bottomLeft2[i][j]; 
				}
			}
		    
		    int[][] bottomRight1 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowMid+1, nums1RowEnd, nums1ColumnStart, nums1ColumnMid, nums2RowStart, nums2RowMid, nums2ColumnMid+1, nums2ColumnEnd);
		    int[][] bottomRight2 = trivialSquareMatrixMultiplyRecursion(nums1, nums2, nums1RowMid+1, nums1RowEnd, nums1ColumnMid+1, nums1ColumnEnd, nums2RowMid+1, nums2RowEnd, nums2ColumnMid+1, nums2ColumnEnd);
		    
		    int[][] bottomRight = new int[bottomRight1.length][bottomRight2[0].length];   //合并第一个部分
		    for (int i = 0; i < bottomRight1.length; i++) {
				for (int j = 0; j < bottomRight2.length; j++) {
					bottomRight[i][j] = bottomRight1[i][j] + bottomRight2[i][j]; 
				}
			}
		    
		    result = new int[(topLeft.length+bottomLeft.length)][topLeft[0].length+topRight[0].length];
		    
		    //将topLeft部分元素赋值给result
		    for(int i = 0 ; i < topLeft.length; i++){
		    	for(int j = 0 ; j < topLeft[0].length; j++){
		    		result[i][j] = topLeft[i][j];
		    	}
		    }
		    
		    //将topRight赋值给result
		    for(int i = 0 ; i < topRight.length ; i++){
		    	for(int j = 0; j < topRight[0].length ; j++){
		    		result[i][j+topLeft[0].length] = topRight[i][j];
		    	}
		    }
		    
		    //bottomLeft赋值给result
		    for(int i = 0 ; i < bottomLeft.length; i++){
		    	for(int j = 0 ; j < bottomLeft[0].length; j++){
		    		result[i+topLeft.length][j] = bottomLeft[i][j]; 
		    	}
		    }
		    
		    //将bottomRight赋值给result
		    for(int i = 0 ; i < bottomRight.length ; i++){
		    	for(int j = 0 ; j < bottomRight[0].length; j++){
		    		result[i+topLeft.length][j+topLeft[0].length] = bottomRight[i][j];
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
	
	
	//从测试我们知道，函数trivialSquareMatrixMultiplyRecursion在每次分块之后，只适拆分之后左右矩阵的维度是相同的，即分块后得到4个2×2矩阵
	@Test
	public void testTrivialSquareMatrixMultiplyRecursion() throws Exception {
		//int[][] nums1 = {{1,2,3,4,5,6,7,8},{3,4,7,6,5,6,7,8},{6,7,8,9,5,6,7,7},{1,1,1,1,5,6,7,7},{1,2,1,1,1,6,7,7},{1,1,1,1,1,1,7,7},{1,1,1,1,1,1,7,7},{1,1,1,1,1,1,7,7}};  //结果正确
		//int[][] nums2 = {{1,2,3,4,5,6,7,8},{3,4,7,6,5,6,7,8},{6,7,8,9,5,6,7,7},{1,1,1,1,5,6,7,7},{1,2,1,1,1,6,7,7},{1,1,1,1,1,1,7,7},{1,1,1,1,1,1,7,7},{1,1,1,1,1,1,7,7}};  //结果正确
		
		//int[][] nums1 = {{1}};  //结果正确
		//int[][] nums2 = {{2}};  //结果正确
	
		int[][] nums1 = {{1,2,3,4},{3,4,5,6},{6,7,8,9},{1,1,1,1}};   //结果正确
		int[][] nums2 = {{1,2,3,4},{3,4,5,6},{6,7,8,9},{1,1,1,1}};   //结果正确
		
		//int[][] nums1 = {{1,2,3},{3,4,5},{6,7,8}};   //结果不正确
		//int[][] nums2 = {{1,2,3},{3,4,5},{6,7,8}};   //结果不正确
		
		//int[][] nums1 = {{3},{5}};    //结果不正确
		//int[][] nums2 = {{6,7}};      //结果不正确
		int nums1RowLength = nums1.length;
		int nums1ColumnLength = nums1[0].length;
		
		int nums2RowLength = nums2.length;
		int nums2ColumnLength = nums2[0].length;
		
		int[][] trivialSquareMatrixMultiplyRecursion = trivialSquareMatrixMultiplyRecursion(nums1, nums2, 0, nums1RowLength-1, 0, nums1ColumnLength-1, 0, nums2RowLength-1, 0, nums2ColumnLength-1);
	    for (int[] is : trivialSquareMatrixMultiplyRecursion) {
			for (int i : is) {
				System.out.print(i + " ");
			}
		}
	}
}
