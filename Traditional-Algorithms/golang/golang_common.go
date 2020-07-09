// golang 实现栈
// 1. 创建栈
st := make([]int8, 0)  //int类型切片，类型取决于需要push入栈的元素的类型
// st := make([]interface{}, 0)   //可以push任意类型的数据，任意类型都实现了空接口
// 2. push元素
st = append(st, int8(10))
// 3. pop元素
value := st[len(st)-1]   //pop出栈顶元素，并且获取到该元素的值
st = st[:len(st)-1]
// 4. 判断栈是否已为空
len(st) == 0


// golang 实现队列
// 1. 创建队列
queue := make([]int8, 0)
// 2. 元素入队
queue = append(queue, int8(10))
// 3. 元素出队
value := queue[0]
queue = queue[1:]
// 4. 判断队列是否为空
len(queue) == 0


// golang 字典基本用法
// 1. 创建字典
dict := make(map[string]int)   //表示string类型的key，int类型的值
// dict := make(map[string]interface{})  //string类型的key。任意类型的值
// 2. 追加元素
dict[key] = value
// 3. 删除key
delete(dict, key)  //删除dict字典中的key
// 4. 遍历
for k, v := range dict {
    fmt.Println(k, v)
}
// 5. 判断dict中是否存在某个元素
if _, ok := dict[key]; ok {
	//说明元素存在
}else {
    //说明元素不存在
}


// golang 排序
sort.Intes([]int8)  //int排序
sort.Strings([]string)  //字符串排序
sort.Slice(s, func(i, j int)bool{return s[i] < s[j]})  //自定义排序，比如在优先级队列中，会用到

// 系统默认最大值与最小值
// int32 最大最小值
math.MaxInt32 // 实际值：1<<31-1
math.MinInt32 // 实际值：-1<<31
// int64 最大最小值（int默认是int64）
math.MaxInt64
math.MinInt64

