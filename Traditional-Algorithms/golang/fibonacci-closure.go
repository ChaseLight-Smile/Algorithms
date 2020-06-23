package main

import "fmt"

// 返回一个“返回int的函数”
func fibonacci() func() int {
	prev, next := 0, 1
	return func() int{
		tmp := prev
		prev, next = next, (prev+next)
		return tmp
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
