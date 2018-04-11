package solution;
/**
 * LeetCode第四题: 寻找两个已经排序好的数组的中位数
 * @author 朱君鹏
 *
 */
public class FindMedian {
	    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
	        int num1Length = nums1.length; //表示num1数组的长度
			int num2Length = nums2.length; //表示num2数组的长度
			int mergeLength = num1Length + num2Length;
			int[] mergeArray = new int[mergeLength];  //创建大数组
			int i = 0 ; //遍历数组num1的指针
			int j = 0 ; //遍历数组num2的指针
			int k = 0 ; //遍历和数组的指针
			for (k=0; k < mergeLength;k++){
				if (i >= num1Length) {  //说明num1数组已经全部遍历完
					if (j >= num2Length) {  //说明num2数组已经遍历完
						break;
					}else {
						mergeArray[k] = nums2[j];
						j++;
						continue;
					}
				}
				
				if (j >= num2Length) { //说明num2数组已经遍历完
					if( i >= num1Length) {
						//说明num1已经遍历完
						break;
					}else{
						mergeArray[k] = nums1[i];
						i++;
						continue;
					}
				}
				
				if (i < num1Length && j < num2Length){
					if(nums1[i] < nums2[j]) {
						mergeArray[k] = nums1[i];
						i++;
					}else{
						mergeArray[k] = nums2[j];
						j++;
					}
				}
				
			}
	        
	        
	        //计算中位数
	        double median = 0;
	        if(mergeLength % 2 !=0){
	            //说明新数组有基数个元素，其中位数一定为中间元素
	            int mid = (0 + mergeLength) / 2;
	            median = (double)mergeArray[mid];
	        }else {
	            int mid = (0 + mergeLength) / 2;
	            int sum = mergeArray[mid] + mergeArray[mid-1] ;
	            median = (double)sum/2;
	        }
	        return median;
	        
	    }
	    
	    public static void main(String[] args) {
			int[] nums1 = {1,3,5,7};
			int[] nums2 = {2,4,6,8};
			System.out.println(findMedianSortedArrays(nums1, nums2));
		}
}
