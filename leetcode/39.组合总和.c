/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void combination(int* candidates,int candidasSize,int target,int** result,int* returnSize,int** returnColSize,int* temp,int n,int sum,int p){
    int i;
    if(sum == target){  //满足要求，将临时数组存入结果数组
        result[*returnSize] = (int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++){
            result[*returnSize][i] = temp[i];
        }
        (*returnColSize)[*returnSize] = n;
        (*returnSize)++;
        return;
    }
    for(i=p;i<candidasSize;i++){    // 依次遍历各常数，满足小于等于target就递归增加
        if((sum + candidates[i]) <= target){
            sum += candidates[i];
            temp[n] = candidates[i];
            combination(candidates,candidasSize,target,result,returnSize,returnColSize,temp,n+1,sum,i);
            sum -= candidates[i];
        }
      
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    //利用递归回溯寻找符合要求的子数组
    *returnColumnSizes = (int*)malloc(sizeof(int)*1000);
    int** result = (int**)malloc(sizeof(int*)*1000);
    int* temp = (int*)malloc(sizeof(int)*1000);
    *returnSize = 0;
    combination(candidates,candidatesSize,target,result,returnSize,returnColumnSizes,temp,0,0,0);
    return result;


}


// @lc code=end

