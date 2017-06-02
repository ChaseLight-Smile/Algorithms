package com.uniplore.solution;

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
        int sqrtNum = 0;
        int count = 0 ;
        //判断一个数是否是素数，只需要判断2-sqrt(n)之间的数即可
        for(int i = 2 ; i < n ; i++ ){
            sqrtNum = (int)Math.sqrt(i);
            int j = 2 ;
            for(; j <= sqrtNum ; j++) {
                if(i % j == 0) {   //说明当前i不是素数
                    break;
                }else{
                    continue;
                }
            }
            if(j == sqrtNum + 1) {
                //说明第二次循环没有找到适当的除尽的数字
                count++;
            }else{
                continue;
            }
        }
        return count;
    }
}
