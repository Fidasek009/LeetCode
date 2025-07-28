package main

import (
	"fmt"
	"reflect"
	"slices"
)

func threeSum(nums []int) [][]int {
	numsMap := make(map[int]int)

	for _, num := range nums {
		val, exists := numsMap[num]
		if !exists {
			val = 0
		}
		numsMap[num] = val + 1
	}

	var res [][]int = [][]int{}

	for x, _ := range numsMap {
		// count is at least 1 here
		numsMap[x]--

		for y, y_count := range numsMap {
			// skip already picked values
			if y_count == 0 {
				continue
			}
			numsMap[y]--

			// find z
			// x + y + z = 0
			// x + y = -z
			var z int = -(x + y)
			z_count, exists := numsMap[z]

			// y <= z to avoid duplicates
			if exists && z_count > 0 && y <= z {
				res = append(res, []int{x, y, z})
			}

			// put it back
			numsMap[y]++
		}

		// kill the values so it doesn't get used again
		numsMap[x] = 0
	}

	return res
}

func test(expected [][]int, got [][]int) {
	// sort the subsets for equality
	for _, val := range expected {
		slices.Sort(val)
	}
	for _, val := range got {
		slices.Sort(val)
	}

	if !reflect.DeepEqual(expected, got) {
		panic(fmt.Sprintf("Expected %v but got %v\n", expected, got))
	}
}

func main() {
	in1 := []int{-1, 0, 1, 2, -1, -4}
	out1 := [][]int{{-1, -1, 2}, {-1, 0, 1}}
	test(out1, threeSum(in1))

	in2 := []int{0, 1, 1}
	out2 := [][]int{}
	test(out2, threeSum(in2))

	in3 := []int{0, 0, 0}
	out3 := [][]int{{0, 0, 0}}
	test(out3, threeSum(in3))
}
