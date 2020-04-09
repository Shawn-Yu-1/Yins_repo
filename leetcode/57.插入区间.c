/*
 * @lc app=leetcode.cn id=57 lang=c
 *
 * [57] 插入区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    //情况太多了，需要模块化，会更清晰
    int** NewIntervals=(int**)malloc(sizeof(int*)*(intervalsSize+1));
    int i,j,p;
    if( (intervals==NULL) || (intervalsSize==0) ){ //判断特殊情况
        NewIntervals[0]= (int*)malloc(sizeof(int)*2);
        NewIntervals[0]=newInterval;
        *returnSize = 1;
        int* collen = (int*)malloc(sizeof(int)*1);
        collen[0] = 2;
        *returnColumnSizes = collen;
        return NewIntervals;
    }
    if((newInterval==NULL)&&(newIntervalSize==0)){ // 另一特殊情况
        *returnSize = intervalsSize;
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }
    for(i=0,j=0;i<intervalsSize;i++){  //归并为一个升序区间
        if(newInterval[0]<intervals[i][0]){
            NewIntervals[j] = newInterval;
            j++;
            break;
        }
        NewIntervals[j] = intervals[i];
        j++;
    }
    
    for(;i<intervalsSize;i++){
        NewIntervals[j] = intervals[i];
        j++;
    }
    if(j==intervalsSize){ //防止新区间没有加入
        NewIntervals[j] = newInterval;
        j++;
        }
    p=j;
    for(i=1,j=0;i<p;i++){ //计算是否需要合拼区间
        if(NewIntervals[j][1]>=NewIntervals[i][0]){
            if(NewIntervals[j][1]<NewIntervals[i][1]){
                NewIntervals[j][1] = NewIntervals[i][1];
            }
        }
        if(NewIntervals[j][1]<NewIntervals[i][0]){
            j++;
            NewIntervals[j]=NewIntervals[i];

        }
    }
    j++;
    *returnSize = j;
    int* collen = (int*)malloc(sizeof(int)*j);
    for(i=0;i<j;i++){
        collen[i] = 2;
    }
    *returnColumnSizes = collen;
    return NewIntervals;
    
}


// @lc code=end

