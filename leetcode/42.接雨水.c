/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 */

// @lc code=start


int trap(int* height, int heightSize){
    int i,j,p,q,r,sum=0,min,inner=0;
    for(i=0;i<heightSize;i++){
        inner=0;
        if(i==heightSize-1)
            break;
        if(height[i]>height[i+1]){
            p=i;
            q=0;
            for(;i<heightSize-1;i++){
                if(height[p]<=height[i+1]){
                        q=i+1;
                        break;
                }
            }
            if(q==0){
                height[p]--;
                i=p-1;
                continue;
            }
            else {
            min=height[p];
            for(j=p+1;j<q;j++)
                inner += height[j];
            printf("%d\n",inner);
            sum += (q-p-1)*min-inner;
            }
        }
    }
    return sum;

}


// @lc code=end

