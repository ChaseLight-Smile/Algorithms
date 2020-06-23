func twoSum(nums []int, target int) []int {
    var s = len(nums)
    var m = map[int]int{}
    for i := 0; i < s; i++ {
        m[nums[i]] = i;
    }

    for i := 0; i < s; i++{
       
        if e, ok := m[target - nums[i]]; ok && i != m[target - nums[i]] {
            return []int{i, e}
        }  
    }
    return nil
}


// 精简版实现
func twoSum(nums []int, target int) []int {
    m := map[int]int{}
    for i := range nums {
        if e, ok := m[target - nums[i]]; ok && i != m[target - nums[i]] {return []int{i, e}}
        m[nums[i]] = i;
    }
    return nil
}


// 初始化map的方式不同
func twoSum(nums []int, target int) []int {
    m := make(map[int]int)  // 和上一种方法初始化map的方式不同
    for i := range nums {
        if e, ok := m[target - nums[i]]; ok && i != m[target - nums[i]] {return []int{i, e}}
        m[nums[i]] = i;
    }
    return nil
}