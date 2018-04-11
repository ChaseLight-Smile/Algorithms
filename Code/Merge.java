package solution;


/**
 * 功能: 合并两个已经排序好的数组，输入: 两个数组分别是int[] num1 ; int[] num2 ,并且这两个数组都已经分别排序好，其各自的数组长度分别为m,n
 * 输出: 将两个数组合并成一个排好序的大数组，并要求时间复杂度为O(n)
 * @author 朱君鹏
 *
 */
public class Merge {
	public static int[] merge(int[] nums1,int[] nums2) {
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
		//输出排序好的大数组
		for(int arr : mergeArray){
			System.out.print(arr + " ");
		}
		System.out.println();
		System.out.println("合并数组过程");
		return mergeArray;
	}
	
	public static void main(String[] args) {
		//int[] num1 = {1,4,7};  //测试组1
		//int[] num2 = {3,6,9};  //测试组2
		//int[] num1 = {2,4,5,7};  //测试组2
		//int[] num2 = {1,2,3,6};  //测试组2
		int[] num1 = {2,2};  //测试组2
		int[] num2 = {2,2};  //测试组2
		//int[] num1 = {4};  //测试组2
		//int[] num2 = {1,2,3,6};  //测试组2
		merge(num1, num2);
	}
}
