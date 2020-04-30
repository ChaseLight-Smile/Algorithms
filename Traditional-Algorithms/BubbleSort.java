package solution;

/**
 * 功能: 实现冒泡排序
 * @author 朱君鹏
 *
 */
public class BubbleSort {

	public static void bubbleSort(int[] arr) {
		int length = arr.length;   //表示数组的长度
		for (int i = 0 ; i < length ; i++) {
			//确定每一个位置的值
			//从后往前冒泡到指定的位置
			for (int j = length -1 ; j > i ; j--) {
				if(arr[j] < arr[j-1]) {
					//则二者发生交换
					int temp = 0;
					temp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = temp;
				}else{
					continue;
				}
			}
		}
	}
	public static void main(String[] args) {
		//int[] arr = {7,6,5,4,3,2,1};  //测试组1
		int[] arr = {31,41,59,26,41,58};   //测试组2
		bubbleSort(arr);
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}
}
