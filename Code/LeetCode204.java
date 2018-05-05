package solution;

/**
 * 功能: LeetCode第204题目，寻找素数(质数)，从素数的定义中我们知道，首先1既不是质数也不是合数，所以我们的测试应该从2开始，对于任何一个数n
 * 如果该数为质数，那么它的约数应该只有1和它本身，按道理来讲，我们应该测试从2-n之前的所有数，看是否存在除尽的情况，但是实际上我们发现并不需要，
 * 只需要测试从2-sqrt(n)之前的数字就可以，因为如果存在约数，那么必定有一个数小于等于sqrt(n)，另一个数大于sqrt(n).
 * @author 朱君鹏
 *
 */
public class LeetCode204 {

	//该方法没有通过LeetCode测试，20个测试，最后的两个超时没有通过
	public int countPrimes(int n) {
		/*int count = 0 ;
		if(isPrime(n)){
			count++;
		}
		return count;*/
		 //素性测试的蒙特克罗方法，这个方法产生的结果太随机，对于很小的数都可能出现计算错误，尽管时间真的很少
        //该算法是随机算法，不能直接用在这里想，需要采用随机算法思想进行改进
        int count = 0 ;  //计数素数
        for(int i = 2 ; i < n ; i++){
            boolean flag = true;
            int a = 0; 
            while(flag){
                a = (int)(java.lang.Math.random()*i);  //随机选择一个小于n的正整数，这里极其有可能会取到0
                if(a == 0){
                    flag = true;
                }else{
                    flag = false;
                }
            }
            
            if((int)((java.lang.Math.pow(a,i-1)-1) % i) == 0){
                count++;
            }else{
                continue;
            }
        }
        return count;
	}
	
	public boolean isPrime(int n){
		 if (n <= 1) return false;
		   for (int i = 2; i * i <= n; i++) {
		      if (n % i == 0) return false;
		   }
		   return true;
	}
	
	public int countPrimes1(int n) {
		int count = 0 ;
		for(int i = 2; i < n; i++){
		    if(isPrime1(i)){
			    count++;
		    }
		}
		
		return count;
	}
	
	public boolean isPrime1(int n){
	   for (int j = 2; j * j <= n; j++) {
	      if (n % j == 0) return false;
	   }
	   return true;
	}
}
