/*
 * @lc app=leetcode.cn id=164 lang=c
 *
 * [164] 最大间距
 */

// @lc code=start
int getindex(int* nums,int low,int high){
    int temp = nums[low];
    while(low<high){
        while(low<high && nums[high]>=temp){
            high--;
        }
        nums[low] = nums[high];
        while(low<high && nums[low]<=temp){
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = temp;
    return low;
}
void quicksort(int* nums,int low,int high){
    if(low<high){
        int pivot = getindex(nums,low,high);
        quicksort(nums,low,pivot-1);
        quicksort(nums,pivot+1,high);
    }
}

int maximumGap(int* nums, int numsSize){
    //先利用快速排序将数组排序，在遍历数组，找到最大差值；
    int i,max = 0;
    quicksort(nums,0,numsSize-1);//快速排序
    for(i=0;i<numsSize-1;i++){
        if((nums[i+1]-nums[i])>max){
            max = nums[i+1] - nums[i];
        }
    }
    return max;

}


// @lc code=end

