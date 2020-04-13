/*
 * @lc app=leetcode.cn id=403 lang=c
 *
 * [403] 青蛙过河
 */

// @lc code=start

int getdone(int* stones,int stonesSize,int** memo,int steps,int p){
    if(memo[p][steps]>=0){
        return memo[p][steps];
    }
   
    for(int i=p+1;i<stonesSize;i++){
        int gap = stones[i] - stones[p];
        if(gap >= steps-1 && gap <= steps+1){
            if(getdone(stones,stonesSize,memo,gap,i) == 1){
                memo[p][gap] = 1;
                return 1;
            }
        }
    }
    memo[p][steps] = (p == stonesSize - 1)?1:0;
    return memo[p][steps];
    
}

bool canCross(int* stones, int stonesSize){
    //测试满足条件的每一个方法，设置memo来防止重复计算
    int** memo = (int**)malloc(sizeof(int*)*stonesSize);
    for(int i=0;i<stonesSize;i++){
        memo[i] = (int*)malloc(sizeof(int)*stonesSize);
        for(int j=0;j<stonesSize;j++){
            memo[i][j] = -1;
        }
    } 
    return getdone(stones,stonesSize,memo,0,0) == 1;

}


// @lc code=end

