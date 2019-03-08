/*
Quesetion 1: Two Sum

Given an array of integers, return INDICES of the two numbers such that they
add up to a specific target.

You may assume that each input would have EXACTLY one solution, and you may
not use the same element twice

[Example]
Given Nums = [2, 7, 11, 15], Target = 9,
return [0, 1] (nums[0] + nums[1] = 2 + 7 = 9)
*/

/* Time: 8ms */
import "sort"

type numberObj struct {
	num   int
	index int
}

//Type Initialize
type numberObjSlice []numberObj

func (n numberObjSlice) Len() int {
	return len(n)
}

func (n numberObjSlice) Less(i, j int) bool {
	return n[i].num < n[j].num
}

func (n numberObjSlice) Swap(i, j int) {
	n[i], n[j] = n[j], n[i]
}

func TwoSum(nums []numberObj, target int) []int {
	i := 0
	j := len(nums) - 1

	for i < j {
		sum := nums[i].num + nums[j].num

		if sum == target {
			return []int{nums[i].index, nums[j].index}
		} else if sum > target {
			j--
		} else {
			i++
		}
	}

	return []int{}
}

func twoSum(nums []int, target int) []int {
	b := []numberObj{}
	for i := 0; i < len(nums); i++ {
		b = append(b, numberObj{index: i, num: nums[i]})
	}

	sort.Sort(numberObjSlice(b))
	return TwoSum(b, target)
}