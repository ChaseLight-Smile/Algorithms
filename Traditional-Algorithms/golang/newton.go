package main

import (
	"fmt"
	"math"
)
const eps = 1e-10

func Sqrt(x float64) float64 {
	z := x
	for z * z - x >= eps || z * z - x <= -eps {
		z -= (z * z - x) / (2 * z)
		fmt.Println("Z is value %v:", z)
	}
	return z
}

func main() {
	fmt.Println(Sqrt(9))
	fmt.Println(math.Sqrt(9))
}