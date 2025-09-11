/*
https://leetcode.com/problems/maximum-subarray/
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 medium
 kadane's algorithm

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/





int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 1) return nums[0];
    int sum = nums[0] < 0 ? 0 : nums[0] ;
    int max = nums[0];
    for(int i=1; i<numsSize; i++) {
        sum += nums[i];
        max = sum > max ? sum : max;
        if(sum <= 0) sum = 0;
    }
    return max;
}
