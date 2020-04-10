/*
 * @lc app=leetcode.cn id=174 lang=c
 *
 * [174] 地下城游戏
 */

// @lc code=start


//递归，好理解，但是比较耗时
void rescueP(int** dungeon,int dungeonSize,int* dungeonColSize,int* min,int col,int clum,int* temp){
    if(col==dungeonSize-1 && clum==(*dungeonColSize)-1){
        temp[col+clum] = dungeon[col][clum];
        int mini = temp[0];
        int sum=0;
        for(int i=0;i<(col+clum+1);i++){
            sum += temp[i];
            if(mini > sum){
                mini = sum;
            }
        }
        if((*min) < mini){
            (*min) = mini;
        }
        return;
    }
    else{
        if(col < (dungeonSize-1)){
            temp[col+clum] = dungeon[col][clum];
            rescueP(dungeon,dungeonSize,dungeonColSize,min,col+1,clum,temp);
        }
        if(clum < (*dungeonColSize)-1){
            temp[col+clum] = dungeon[col][clum];
            rescueP(dungeon,dungeonSize,dungeonColSize,min,col,clum+1,temp);
        }
    }
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize){
    int* min=(int*)malloc(sizeof(int)*1);
    int* temp=(int*)malloc(sizeof(int)*(dungeonSize+(*dungeonColSize)));
    (*min) = -__INT32_MAX__;
    if(dungeonSize==0||dungeonColSize==0){
        return 1;
    }
    rescueP(dungeon,dungeonSize,dungeonColSize,min,0,0,temp);
    printf("%d",*min);
    if((*min)>0){
        return 1;
    }
    else{
        return (-(*min))+1;
    }

}


// @lc code=end

