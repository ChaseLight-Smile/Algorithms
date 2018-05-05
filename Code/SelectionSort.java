package solution;

/**
 * 功能: 实现选择排序，首先假设第一个元素的最小的，然后分别和后面的元素比较，如果选出后续最小的元素和arr[0]交换，
 * 接着再分别找到arr[i]...arr[i-1]的元素，最后的结果就已经是排序好的整个数组
 * @author 朱君鹏
 *
 */
public class SelectionSort {

	public static void selectionSort(int[] arr) {
		int length = arr.length ;
		for (int i = 0 ; i <= length - 1; i++) {
			int min = arr[i];   //假设当前元素就是该位置上的最小值
			for(int j = i+1; j <= length -1 ; j++){
				if(min > arr[j]) {
					int temp = 0;
					temp = arr[j];
					arr[j] = min;
					min = temp;
				}else {
					continue;
				}
			}
			arr[i] = min;    //将min的值赋值给当前位置，这就是最小值
		}
	}
	
	public static void main(String[] args) {
		//int[] arr = {31,41,59,26,41,58};   //测试组1
		int[] arr = {7,6,5,4,3,2,1};   //测试组2
		selectionSort(arr);
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
}
