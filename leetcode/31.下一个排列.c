/*
 * @lc app=leetcode.cn id=31 lang=c
 *
 * [31] 下一个排列
 */

// @lc code=start


void nextPermutation(int* nums, int numsSize){
    int i,j,temp;
    for(i=numsSize-1;i>0;i--){
        if(i>=1&&nums[i-1]<nums[i]){
            for(j=i;(j<numsSize)&&(nums[i-1]<nums[j]);j++);
            temp = nums[j-1];
            nums[j-1] = nums[i-1];
            nums[i-1] = temp;
            printf("%d",nums[1]);
            for(j=i;j<=(numsSize+i-1)/2;j++){
                temp = nums[j];
                nums[j] = nums[numsSize+i-j-1];
                nums[numsSize+i-j-1] = temp;
            }
            break;
                
         }
        }
    if(i==0){
        for(i=0;i<(numsSize/2);i++){
            temp = nums[i];
            nums[i] = nums[numsSize-1-i];
            nums[numsSize-1-i] = temp;
        }
    }

}


// @lc code=end

