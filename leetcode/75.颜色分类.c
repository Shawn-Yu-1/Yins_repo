/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */

// @lc code=start


void sortColors(int* nums, int numsSize){
int temp,i,j=numsSize-1;
for(i=0;i<numsSize;i++){
    if(i>=j)
        break;
    if(nums[i]==0);

    else
        for(;j>i;j--)
            if(nums[j]==0){
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                break;
            }  
}
    j=numsSize-1; //重置j的初值，防止if跳出
for(i=0;i<numsSize;i++){
    if(i>=j)
        break;
    if(nums[i]==2)
        for(;j>i;j--)
            if(nums[j]==1){
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                break;
            }

        }
    return nums;

}


// @lc code=end

