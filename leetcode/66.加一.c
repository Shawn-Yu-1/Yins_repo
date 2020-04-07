/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* result=(int*)malloc(sizeof(int)*100);
    int i,j,k,up=1;
    if(digits[0]!=9&&digitsSize==1){
        *returnSize = 1;
        result[0]=digits[0]+1;
        return result;
    }
    if(digits[0]==9&&digitsSize==1){
        *returnSize=2;
        result[0]=1;
        result[1]=0;
        return result;
    }
    
    if(digits[digitsSize-1]!=9){
        digits[digitsSize-1] = digits[digitsSize-1] + 1;
        *returnSize = digitsSize;
        return digits;
        }
    
    for(i=digitsSize-1;i>=0;i--){
        if(i==0&&(digits[0]+up)==10){
            result[0]=1;
            result[1]=0;
            for(i=1,j=2;i<digitsSize;i++,j++){
                result[j] = digits[i];
            }
            *returnSize = digitsSize + 1;
            return result;
        }
        if(digits[i]+up == 10){
            digits[i] = 0;
            up = 1;
        }
        else{
            digits[i] = digits[i] + up;
            up = 0;
            *returnSize = digitsSize;
            return digits;
        }
    }
return digits;

}


// @lc code=end

