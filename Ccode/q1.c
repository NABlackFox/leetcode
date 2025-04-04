/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include "stdio.h"
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int)); // Allocate memory
    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (*(nums + i) + *(nums + j) == target){
                int* result = (int*)malloc(2 * sizeof(int)); // Allocate memory
                result[0] = i;
                result[1] = j;
                *returnSize = 2; // Indicating that two elements are returned
                return result;
            }
        }

        
    }
    return result;
}

int main(){
    return 0;
}
