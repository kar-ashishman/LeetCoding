/*
Medium
Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
void exactmatch(int l, int r, int size, int target, int *nums, int *res, int *found) {
    while(l >= 0) {
        if(nums[l] != target) break;
        else l--;
    }
    l++;
    
    while(r <= size) {
        if(nums[r] != target) break;
        else r++;
    }
    r--;
    res[0] = l;
    res[1] = r;
    *found = 1;
}


void leftmatch(int l, int size, int target, int *nums, int *res, int *found) {
    int left = l+1;
    while(l >= 0) {
        if(nums[l] != target) break;
        else l--;
    }
    l++;
    
    while(left <= size) {
        if(nums[left] != target) break;
        else left ++;
    }
    left --;
    res[0] = l;
    res[1] = left;
    *found = 1;
}


void rightmatch(int r, int size, int target, int *nums, int *res, int *found) {
    int right = r-1;
    while(r <= size) {
        if(nums[r] != target) break;
        else r++;
    }
    r--;
    
    while(right >= 0) {
        if(nums[right] != target) break;
        else right --;
    }
    right ++;
    res[0] = right;
    res[1] = r;
    *found = 1;
}


void finder(int *nums, int l, int r, int size, int target, int *res, int *found) {
    
    if(nums[l] == target && nums[r] == target) {
        exactmatch(l,r,size,target,nums,res, found);
    }
    
    else if(nums[l] == target && nums[r] > target) {
        leftmatch(l,size,target, nums, res, found);
    }
    
    else if(nums[l] < target && nums[r] == target) {
        rightmatch(r,size,target,nums,res,found);
    }
    
    else if(nums[l] < target && nums[r] > target) {
        // find left half
        finder(nums,l, (int)((l+r)/2),size,target,res,found);
        finder(nums,(int)((l+r)/2)+1,r,size,target,res,found);
    }
    
    if(*found == 1) return;
}

#include<stdio.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *res = (int *) malloc(sizeof(int)*2);
    res[0] = -1;
    res[1] = -1;
    if(numsSize == 0) return res;
    if(numsSize == 1) {
        if(nums[0] == target) {
            res[0] = 0;
            res[1] = 0;
            return res;
        }
        else return res;
    }

    int found = 0;
    finder(nums,0,numsSize-1,numsSize-1,target,res,&found);
    return res;
}
