package solution;

/**
 * 功能: 插入排序思想很简单，假设要将一个数组按非递减顺序排序，那么首先假设从左到右以此都是排序好的，从第二个元素开始与其左侧位置进行比较，并将
 * 该元素放置在合适的位置上，该算法最坏情况下的时间复杂度为O(n^2)，n为输入规模
 * @author 朱君鹏
 *
 */
public class InsertSort {

	public static void insertSort(int[] arr) {
		int length = arr.length;
		for (int i = 1;i < length ; i++) {
			for (int j = 0 ; j < i ; j++) {  //从第二个元素开始，与之前的元素进行比较
				if (arr[i] < arr[j]) {   //如果第i个元素比其左侧的元素小，则发生移动
					int temp = 0;
					temp = arr[i];
					//发生移动的部分，整体发生移动，而不是调换某两个元素的位置，这个过程并没有把arr[i]放入其中，有可以将其放入
					for (int k = i-1;;k--) {
						if (k == j -1) {
							break;
						} else {
							arr[k+1] = arr[k];
						}
					}
					arr[j] = temp ;
				}
				else{
					continue;
				}
			}   //j for循环结束
		}    //i for循环结束 
		
		/* 在插入排序中使用冒泡排序过程，也即当前元素之前部分已经排序好，那么当前元素在其左侧部分怎么找到
		 * 合适的位置？本段代码使用冒泡排序
		 * */
		/*for (int i = 1; i < length ; i++){
			for (int j = i -1 ; j >= 0 ; j--) {
				if (arr[j+1] < arr[j]) {
					int temp = 0;
					temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}  //j for循环结束
		}  // i for循环结束  		
*/	}
	
	//插入排序的递归版本
	public static int[] insertSortRecurtion(int[] arr,int length){
		if(length == 1){
			return arr;
		}
		arr = insertSortRecurtion(arr, length-1);
		return arr;
	}
	public static void main(String[] args) {
		int[] arr = {5,4,3,2,1};  //测试组1
		//int[] arr = {5,2,4,6,1,3};   //测试组2
		//int[] arr = {-1,2,100,-100,30,-23,90};
		//int[] arr = {31,41,59,26,41,58};
		//int[] arr ={1};
		insertSort(arr);
		
		//遍历输出排序后的结果
		for (int i : arr) {
			System.out.print(i + " ");   //输出排序后的结果
		}
		
		System.out.println();
		System.out.println("调用递归算法");
		int length = arr.length;
		int[] insertSortRecurtion = insertSortRecurtion(arr, length);
		for (int i : insertSortRecurtion) {
			System.out.print(i + " ");
		}
	}
}
