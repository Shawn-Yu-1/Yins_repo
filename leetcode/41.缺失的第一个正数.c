/*
 * @lc app=leetcode.cn id=41 lang=c
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start


int firstMissingPositive(int* nums, int numsSize){
    int temp[numsSize+2];
    int i;
    for(i=0;i<=numsSize+1;i++){
        temp[i] = 0;
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]>0&&nums[i]<numsSize+1){
            temp[nums[i]] = 1;
        }
    }
    for(i=1;i<numsSize+2;i++){
        if(temp[i]==0){
            break;
        }
    }
    return i;

}


// @lc code=end

