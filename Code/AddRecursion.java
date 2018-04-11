package solution;

public class AddRecursion {
	public static int addRecursion(int[] nums, int length){
		int sum = 0 ;
		if(length == 1) {
			sum += nums[0];
			return sum;
		}
		
		sum = addRecursion(nums, length-1);  //将返回的和值赋值给sum变量
		sum += nums[length-1];
		return sum;
	}
	
	public static void main(String[] args) {
		int[] nums = {1,2,3,4,5,6,7,8,9,10};
		int length = nums.length;
		int sum = addRecursion(nums, length);
		System.out.println(sum);
	}
}
