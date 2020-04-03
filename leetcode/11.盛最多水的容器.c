/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start


int maxArea(int* height, int heightSize){
    int i,j,max=0,min;
    for(i=0;i<heightSize-1;i++){
        j=i+1;
        for(;j<heightSize-1;j++)
            if(height[j]>height[j+1])
                break;
        for(;j<heightSize;j++){
            min=(height[i]<height[j])?height[i]:height[j];
            if(max<min*(j-i))
                max=min*(j-i);
        }
    }
    return max;


}


// @lc code=end

