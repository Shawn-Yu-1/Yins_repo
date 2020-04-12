/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void combination(int* candidates,int candidasSize,int target,int** result,int* returnSize,int** returnColSize,int* temp,int n,int sum,int p,int* c){
    int i,j;
    if(sum == target){  //满足要求，将临时数组存入结果数组
        result[*returnSize] = (int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++){
            result[*returnSize][i] = temp[i];
        }
        (*returnColSize)[*returnSize] = n;
        (*returnSize)++;
        *c = 1;
        return;
    }
    for(i=p;i<candidasSize;i++){    // 依次遍历各常数，满足小于等于target就递归增加
        if(n > 0 && candidates[i-1]!=candidates[i]){
            j=1;
        }
        if( j == 0 && (*c)==1 && candidates[i-1]==candidates[i]){
            continue;
        }
        if(i>0 && n==0 && candidates[i-1]!=candidates[i]){
            *c = 0;
        }
           
        if((sum + candidates[i]) <= target){
            sum += candidates[i];
            temp[n] = candidates[i];
            combination(candidates,candidasSize,target,result,returnSize,returnColSize,temp,n+1,sum,i+1,c);
            sum -= candidates[i];
            j=0;
        }
      
    }
}

int getindex(int* candidates,int low,int high){  
    int temp = candidates[low];
    while(low<high){
        while(low<high && candidates[high]>=temp){
            high--;
        }
        candidates[low] = candidates[high];
        while(low<high && candidates[low] <= temp){
            low++;
        }
        candidates[high] = candidates[low];

    }
    candidates[low] = temp;
    return low;
 }
 void quicksort(int* candidates,int low,int high){
     if(low<high){
         int pivot = getindex(candidates,low,high);
         quicksort(candidates,low,pivot-1);
         quicksort(candidates,pivot+1,high);
     }
 }
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    quicksort(candidates,0,candidatesSize-1);
    for(int i=0;i<candidatesSize;i++){
        printf("%d ",candidates[i]);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*1000);
    int** result = (int**)malloc(sizeof(int*)*1000);
    int* temp = (int*)malloc(sizeof(int)*1000);
    int* count = (int*)malloc(sizeof(int)*1);
    *count = 0;
    *returnSize = 0;
    combination(candidates,candidatesSize,target,result,returnSize,returnColumnSizes,temp,0,0,0,count);
    return result;

}


// @lc code=end

