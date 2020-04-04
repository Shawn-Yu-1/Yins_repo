/*
 * @lc app=leetcode.cn id=134 lang=c
 *
 * [134] 加油站
 */

// @lc code=start


int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int i,j,vol;
    for(i=0;i<gasSize;i++){
        vol=gas[i];
        for(j=i+1;j%gasSize!=i;j++){
            if((vol-cost[(j-1)%gasSize])>=0)
                vol=vol-cost[(j-1)%gasSize]+gas[j%gasSize];
            else
                break;  
        }
        if(j%gasSize==i){
            if((vol-cost[(j-1)%gasSize])>=0)
                return i;    
        }

    }
    return -1;

}


// @lc code=end

