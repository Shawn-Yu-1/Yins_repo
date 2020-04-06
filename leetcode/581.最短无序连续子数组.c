/*
 * @lc app=leetcode.cn id=581 lang=c
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start


int findUnsortedSubarray(int* nums, int numsSize){
    /*计算连续最短无序，及除去首部最大升序和尾部最大升序，如果不存在，则该数组全部有序*/
    int max,min,i,tail=0,front=0;
    if(numsSize==1)
        return 0;
    max = nums[0];
    min = nums[numsSize-1];
    for(i=0;i<numsSize;i++){  //计算尾序列有序个数
        if(max>nums[i])
            tail = 0;
            
        else{
            max = nums[i];
            tail++;
        }
    }
    for(i=numsSize-1;i>=0;i--){ //计算头序列有序个数
        if(min<nums[i])
            front = 0;
        else{
            min = nums[i];
            front++;
        }
        
    }
    if(front==numsSize&&tail==numsSize)
        return 0;
    return numsSize-front-tail;


}


// @lc code=end

