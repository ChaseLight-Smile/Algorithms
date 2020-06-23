/**
练习：map
实现 WordCount。它应当返回一个映射，其中包含字符串 s 中每个“单词”的个数。
函数 wc.Test 会对此函数执行一系列测试用例，并输出成功还是失败。
https://tour.go-zh.org/moretypes/23
*/

package main

import (
	"golang.org/x/tour/wc"
	"strings"
)

func WordCount(s string) map[string]int {
	m := make(map[string]int)  // 创建映射
	c := strings.Fields(s)  // 会按照"\t" " " "\n"等这些分隔开
	for _, v := range c {  //每出现相同的单词（字符串）
		m[v] += 1  //出现次数就 + 1         
    }
   return m
}

func main() {
	wc.Test(WordCount)
}
