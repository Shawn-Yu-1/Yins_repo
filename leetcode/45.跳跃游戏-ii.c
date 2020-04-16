/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start


int jump(int* nums, int numsSize){
    //采用动态规划，从结尾到开始，以此计算该位置跳到结尾的最短距离（如果存在的话），最后返回temp[0]即为最少跳数
    int temp[numsSize];//最少跳数数组
    int i,j,min,c;
    temp[numsSize-1] = 0;//末尾初始化为零
    for(i=numsSize-2;i>=0;i--){//从尾到头进行遍历
        c=0;
        min = __INT32_MAX__;
        if(nums[i]>=(numsSize-i-1)){//如果可以一步调到结尾，跳数为一
            temp[i] = 1;
            continue;
        }
        if(nums[i]==0){//该数为零，则无法到达结尾
            temp[i] = -1;
            continue;
        }
        for(j=nums[i];j>0;j--){//无法一次跳到结尾，统计最少跳数
            if(temp[i+j]+1==2 && temp[i+j]!= -1){
                c = 1;
                temp[i] = 2;
                break;
            }
            if(temp[i+j]!= -1 && temp[i+j]+1 < min){
                c = 1;
                min = temp[i+j] + 1;
                temp[i] = min;
            }
        }
        if(c==0){
            temp[i] = -1;
        }
    }
    return temp[0];

}


// @lc code=end

