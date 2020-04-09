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
    int left;
    int i,j,lenth;
    if( (intervals==NULL) || (intervalsSize==0) ){
        NewIntervals[0]= (int*)malloc(sizeof(int)*2);
        NewIntervals[0]=newInterval;
        *returnSize = 1;
        int* collen = (int*)malloc(sizeof(int)*1);
        collen[0] = 2;
        *returnColumnSizes = collen;
        return NewIntervals;
    }
    if((newInterval==NULL)&&(newIntervalSize==0)){
        *returnSize = intervalsSize;
        *returnColumnSizes = intervalsColSize;
        return intervals;
    }
    for(left=0;left<intervalsSize;left++){
        if(intervals[left][0]>newInterval[0]){
            break;
        }
    }
    if(left==intervalsSize){  //新插入区间在末尾；
        for(i=0;i<intervalsSize-1;i++){
            NewIntervals[i]=(int*)malloc(sizeof(int)*2);
            NewIntervals[i] = intervals[i];
        }
        if(newInterval[0]<=intervals[i][1]){
            newInterval[0] = intervals[i][0];
            if(newInterval[1]<intervals[i][1]){
                newInterval[1] = intervals[i][1];
            }
            NewIntervals[i]=(int*)malloc(sizeof(int)*2);
            NewIntervals[i] = newInterval;
        }else{
        NewIntervals[i]=(int*)malloc(sizeof(int)*2);
        NewIntervals[i] = intervals[i];
        i++;
        NewIntervals[i]=(int*)malloc(sizeof(int)*2);
        NewIntervals[i] = newInterval;
        }
        *returnSize = i+1;
        int* collen = (int*)malloc(sizeof(int)*(i+1));
        for(j=0;j<i+1;j++){
        collen[j]=2;
        }
        *returnColumnSizes = collen;
        return NewIntervals;
    }
    if(left==0){ //新插入区间在开头
        if(newInterval[1]<intervals[0][0]){
            i=0;
            NewIntervals[i]=(int*)malloc(sizeof(int)*2);
            NewIntervals[i] = newInterval;
            for(j=0;j<intervalsSize;j++){
                NewIntervals[j+1]=(int*)malloc(sizeof(int)*2);
                NewIntervals[j+1] = intervals[j];
                }
            *returnSize = j+1;
            int* collen = (int*)malloc(sizeof(int)*(j+1));
            for(i=0;i<j+1;i++){
            collen[i]=2;
                }
            *returnColumnSizes = collen;
            return NewIntervals;
            }
            
    }
    if(left!=0){
        left--;
    }
    for(i=0;i<left;i++){
        NewIntervals[i]=(int*)malloc(sizeof(int)*2);
        NewIntervals[i] = intervals[i];
    }
    j = i;
    for(;i<intervalsSize;i++){ //插在中间
        if(newInterval[0]>intervals[i][0]&&newInterval[0]<=intervals[i][1]){
            newInterval[0] = intervals[i][0];
        }
        else{
            if(newInterval[0]>intervals[i][1]){
            NewIntervals[j]=(int*)malloc(sizeof(int)*2);
            NewIntervals[j] = intervals[i];
            j++;}

        }
        if(newInterval[1]<intervals[i][1]&&newInterval[1]>=intervals[i][0]){
            newInterval[1] = intervals[i][1];
        }
        
        if((i+1)<intervalsSize && newInterval[1]<intervals[i+1][0]){
            NewIntervals[j]=(int*)malloc(sizeof(int)*2);
            NewIntervals[j] = newInterval;
            i++;
            j++;
            break;
        }
    }
    if(i==intervalsSize){
        NewIntervals[j]=(int*)malloc(sizeof(int)*2);
        NewIntervals[j] = newInterval;
        j++;
    }
    for(;i<intervalsSize;i++,j++){
        NewIntervals[j]=(int*)malloc(sizeof(int)*2);
        NewIntervals[j] = intervals[i]; 
    }
    int* collen = (int*)malloc(sizeof(int)*j);
    for(i=0;i<j;i++){
        collen[i]=2;
    }
    *returnSize = j;
    *returnColumnSizes = collen;
    return NewIntervals;

}


// @lc code=end

