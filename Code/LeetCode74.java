package solution;

public class LeetCode74 {
	public boolean searchMatrix1(int[][] matrix, int target) {
        int rowLength = matrix.length ;  //计算矩阵的行
        int columnLength = 0;  
        if(rowLength == 0) {
            return false;
        }else{
            columnLength = matrix[0].length; //计算矩阵的列
        }
        
        if(rowLength == 1 && columnLength == 0){
            return false;
        }
        //1. 矩阵中第一个元素是最小的，如果比这个元素还小，说明根本不可能找到target
        if(target < matrix[0][0]){
            //小于第一个元素，说明根本不存在这个元素
            return false;
        }  //逻辑正确
        
        //2. 将第一列拿出来做成一个单独的数组
        int[] binaryArray = new int[rowLength];
        for(int i = 0 ; i < rowLength ; i++) {
           binaryArray[i] = matrix[i][0];
           if(matrix[i][0] == target){
               return true;
           }else{
               continue;
           }
        }
        
        //3. 如果target > 第一列的最一后个元素，此时只需要在最后一行进行检索即可
        if(target > binaryArray[rowLength-1]) {
            boolean result = binarySearch(matrix[rowLength-1], 0 , columnLength-1,target);
            if(result == true){
                return true;
            } 
        }
        
    
        //4. 看是否在第一个元素之后，最后一行的第一个元素之前
        for(int i = 0 ; i < rowLength-1 ; i++){
            if(binaryArray[i] < target && binaryArray[i+1] > target){
                //说明此时元素一定位于第i行，需要在第i行进行检索
                boolean result = binarySearch(matrix[i],0,columnLength-1,target);
                if(result == true){
                    return true;
                }else{
                    return false;
                }
            }else{
                continue;
            }
        }
        
        return false;
    }
    
	public boolean searchMatrix2(int[][] matrix, int target) {
        int rowLength = matrix.length ;  //计算矩阵的行
        int columnLength = 0;  
        if(rowLength == 0) {
            return false;
        }else{
            columnLength = matrix[0].length; //计算矩阵的列
        }
        
        if(rowLength == 1 && columnLength == 0){
            return false;
        }
        
        //直接进行二分检索
        for(int i = 0 ; i < rowLength ; i++){
            boolean result = binarySearch(matrix[i],0, columnLength-1,target);
            if(result == true){
                return true;
            }else{
                continue;
            }
        }
        return false;
    }
    public  boolean binarySearch(int[] arr,int start,int end , int target){
        boolean result = false;
		if (start >= end && target != arr[start]) {
		    result = false;
			return result;
		}
		int mid = (start + end) / 2;  //找到数组的中间位置
		if (target == arr[mid]) {
		    result = true ;
			return result;
		}else if(target > arr[mid]) {
			result = binarySearch(arr, mid+1, end, target);
		}else if(target < arr[mid]){
			result = binarySearch(arr, start, mid-1, target);
		}
		return result;
	}
}
