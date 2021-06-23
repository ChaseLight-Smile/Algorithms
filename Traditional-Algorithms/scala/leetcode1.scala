object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        for(i <- 0 to nums.length - 2; j <- i + 1 to nums.length-1){
            if(nums(i) + nums(j) == target) return Array(i, j) 
        }
        return Array()
    }
}