/*
 * @lc app=leetcode.cn id=554 lang=c
 *
 * [554] 砖墙
 */

// @lc code=start


int leastBricks(int** wall, int wallSize, int* wallColSize){
    int i,j,k,count,min=wallSize,rowlen=0,sum,p,q;
    for(i=0;i<wallColSize[0];i++)
        rowlen += wall[0][i];
    p=wall[0][0];
    q=wall[0][wallColSize[0]-1];
    for(i=0;i<wallSize;i++){
        if(p>wall[i][0])
            p=wall[i][0];
        if(q>wall[i][wallColSize[i]-1])
            q=wall[i][wallColSize[i]-1];    
    }
    if(p==rowlen)
        return wallSize;
    for(i=p;i<=(rowlen-q);i++){
        count=0;
        for(j=0;j<wallSize;j++){
            sum = 0;
            for(k=0;sum<rowlen;k++){
                sum += wall[j][k];
                if(sum==i)
                    break;
                if(sum<i)
                    continue;
                if(sum>i){
                    count++;
                    break;
                }
            }
        }
        if(count<min)
            min = count;

    }
    return min;
    

}


// @lc code=end

