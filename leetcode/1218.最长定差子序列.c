/*
 * @lc app=leetcode.cn id=1218 lang=c
 *
 * [1218] 最长定差子序列
 */

// @lc code=start


int longestSubsequence(int* arr, int arrSize, int difference){
    int i,j,k,max=1,count=1,p=0,temp;
    for(i=0;i<arrSize;i++){
        temp=arr[i]+difference;
        for(j=i;j<arrSize;j++){
            p=0;
            for(k=j+1;k<arrSize;k++){
                if(arr[k]==temp){
                    p=1;
                    temp +=difference;
                    j=k-1;
                    count++;
                    break;    
                }
            }
            if(p==0){
                break;
            }
        }
        if(max<count){
            max=count;
        }
        count=1;
    }
    return max;

}


// @lc code=end

