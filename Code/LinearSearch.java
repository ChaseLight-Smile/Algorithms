package solution;


public class LinearSearch {
	
	//线性查找的递归版本，能用循环代替一般不建议使用递归技术
	public static void linearSearchRecursion(int[] arr,int search,int target){
		if (search < 0) {
			System.out.println("没有找到对应的元素");
			return;
		}
		//search表示查找的位置，给定一个位置
		if(arr[search] == target){
			System.out.println("找到对应的元素");
			return;
		}else {
			linearSearchRecursion(arr, search-1, target);
		}
	}
	
	public static void linearSearch(int[] arr,int target){
		int length = arr.length;
		for (int i = 0 ; i < length ; i++){
			if(target == arr[i]){
				System.out.println("找到指定的元素");
				return;
			}else{
				continue;
			}
		}
		System.out.println("没有找到指定的元素");
		return;
	}
	public static void main(String[] args) {
		int[] arr = {1,3,5,7};
		int target = 0;
		linearSearchRecursion(arr, 3, target);
		linearSearch(arr, target);
	}
}
