package solution;

public class MergeSort {

	/*public static int[] mergeSort(int[] arr , int start ,int end) {
		if(start < end) {
			int mid = ((start + end) / 2 );
			int[] leftArray = mergeSort(arr, start, mid);   //排序左边的部分
			int[] rightArray = mergeSort(arr, mid + 1, end);  //排序右边的部分
			
			int[] result = Merge.merge(leftArray, rightArray);
			return result;
		}
		int[] result = {arr[start]};
		return result;
		
	}*/
	
	/*public static int[] mergeSort(int[] arr , int start ,int end) {
		int[] result = {};
		
		//基本递归结束情况下，如果一个数组只含有一个元素时，这个元素一定是排序好的(平凡的结果)，直接返回该元素即可
		if(start == end){
			result = new int[1];
			result[0] = arr[start];
			return result;
		}
		
		//如果一个数组中仅仅包含有两个元素，则直接对他们进行插入排序(或者直接交换两者的顺序即可)，实际上这里还可以改，当小于等于4个元素时，采用插入排序
		if(end == (start + 1)){
			result = new int[2];
			if(arr[start] > arr[end]){
				//交换两个元素
				int temp = 0;
				temp = arr[start];
				arr[start] = arr[end];
				arr[end] = temp;
				result[0] = arr[start];
				result[1] = arr[end];
				return result;
			}else{
				result = new int[2];
				result[0] = arr[start];
				result[1] = arr[end];
				return result;
			}
		}
		
		if(end >= (start+2)) {
			int mid = ((start + end) / 2 );
			
			//归并过程
			int[] leftArray = mergeSort(arr, start, mid);   //排序左边的部分
			int[] rightArray = mergeSort(arr, mid + 1, end);  //排序右边的部分
			result = Merge.merge(leftArray, rightArray);
			
			return result;
		}
		return result;
	}*/
	
	//当小于等于4个元素时，采用插入排序，在归并中采用插入排序，因为当元素数目很小时，插入排序优于归并排序
	public static int[] mergeSort(int[] arr , int start ,int end) {
		int[] result = {};
		
		if(end <= start+3){
			//直接采用插入排序，从start到end
			for(int i = start+1; i <= end ; i++){
				for(int j = i - 1 ; j >= start ; j--){
					if (arr[j+1] < arr[j]) {
						int temp = 0;
						temp = arr[j+1];
						arr[j+1] = arr[j];
						arr[j] = temp;
					}
				}
			}
			result = new int[end-start+1];
			
			for(int i = 0 ; i < end-start+1 ; i++){
				result[i] = arr[start+i];
			}
			return result;
		}else{
			int mid = ((start + end) / 2 );
			
			//归并过程
			int[] leftArray = mergeSort(arr, start, mid);   //排序左边的部分
			int[] rightArray = mergeSort(arr, mid + 1, end);  //排序右边的部分
			result = Merge.merge(leftArray, rightArray);
			
			return result;
		}
		
	}
	public static void main(String[] args) {
		//int[] arr = {2,4,5,7,1,2,3,6};  //测试组1
		//int[] arr = {7,6,5,4,3,2,1};  //测试组2
		int[] arr = {3,41,52,26,38,57,9,49};  //测试组2
		//int[] arr = {5,4,3};  //测试组4，很重要的测试组
		int length = arr.length;
		int[] mergeSort = mergeSort(arr, 0, length-1);  //从0开始计数
		//System.out.println(mergeSort.length);
		for (int a : mergeSort) {
			System.out.print(a+ " ");
		}
	}
}
