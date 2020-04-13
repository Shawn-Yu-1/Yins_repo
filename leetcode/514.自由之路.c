/*
 * @lc app=leetcode.cn id=514 lang=c
 *
 * [514] 自由之路
 */

// @lc code=start


void minstep(char* ring,char* key,int* min,int count,int steps,int p){
    int i,left,right,len,temp,k;
    len = strlen(ring);
    if(count == strlen(key)){
        if(steps < (*min)){
            *min = steps;
        }
        return;
    }
    if(ring[p] == key[count]){
        minstep(ring,key,min,count+1,steps+1,p);  
    }
    else{
        for(left=p;ring[left%len] != key[count];left++);
        for(temp=right=p;ring[temp%len] != key[count];right--,temp = (temp-1+len)%len);
        if((left%len) == (temp%len)){
            k = ((left-p)<(p-right)?(left-p):(p-right));
            minstep(ring,key,min,count+1,steps+k+1,left%len);
        }
        else{
            minstep(ring,key,min,count+1,steps+left-p+1,left%len);
            minstep(ring,key,min,count+1,steps+p-right+1,temp%len);
        }
    } 
}
int findRotateSteps(char * ring, char * key){
    //递归，寻找所有可能方式，取最少步数
    int* min = (int*)malloc(sizeof(int)*1);
    (*min) = __INT32_MAX__;
    minstep(ring,key,min,0,0,0);
    return *min;
}


// @lc code=end

