/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int i,j,p;
    int** swap = (int**)malloc(sizeof(int*)*1);
    swap[0] = (int*)malloc(sizeof(int)*2);
    if(intervalsSize==0){
        *returnSize = 0;
        return intervals;
    }
    
    for(i=0;i<intervalsSize;i++){ // 选择排序，把区间按开始位置升序排列
        p=i;
        for(j=i;j<intervalsSize;j++){
            if(intervals[p][0]>intervals[j][0]){
                p = j;
            }
        }
        swap[0] = intervals[i];
        intervals[i] = intervals[p];
        intervals[p] = swap[0];
    }
    for(i=1,j=0;i<intervalsSize;i++){ //计算是否需要合拼区间
        if(intervals[j][1]>=intervals[i][0]){
            if(intervals[j][1]<intervals[i][1]){
                intervals[j][1] = intervals[i][1];
            }
        }
        if(intervals[j][1]<intervals[i][0]){
            j++;
            intervals[j]=intervals[i];

        }
    }
    j++;
    *returnSize = j;
    int* collen = (int*)malloc(sizeof(int)*j);
    for(i=0;i<j;i++){
        collen[i] = 2;
    }
    *returnColumnSizes = collen;
    return intervals;
}


// @lc code=end

