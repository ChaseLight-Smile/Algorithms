// 方法一： 考察to与until的区别，to是[a, b]区间，until是[a, b)区间
object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        for(i <- 0 to nums.length - 2; j <- i + 1 to nums.length-1){
            if(nums(i) + nums(j) == target) return Array(i, j) 
        }
        return Array()
    }
}

object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        for(i <- 0 until nums.length - 1; j <- i + 1 until nums.length){
            if(nums(i) + nums(j) == target) return Array(i, j) 
        }
        return Array()
    }
}