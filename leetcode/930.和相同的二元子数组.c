/*
 * @lc app=leetcode.cn id=930 lang=c
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start

void subarray(int* A,int ASize,int s,int position,int* count,int* temp){
    int i,sum=0;
    if(position < 0){
        return;
    }
    temp[position] = A[position] + temp[position+1];
    if(temp[position] < s){
        subarray(A,ASize,s,position-1,count,temp);
    }
    else{
    if(temp[position] == s){
            (*count)++;
        }
    for(i=ASize-1;i>position;i--){
        sum = temp[position] - temp[i];
        if(sum == s){
            (*count)++;
        }
        if(sum < s){
            break;
        }
    }
    subarray(A,ASize,s,position-1,count,temp);
    }

}
int numSubarraysWithSum(int* A, int ASize, int S){
    // 递归，易懂，就是耗时
    int* count=(int*)malloc(sizeof(int)*1);
    int* temp = (int*)malloc(sizeof(int)*(ASize+1));
    temp[ASize] = 0;
    *count = 0;
    subarray(A,ASize,S,ASize-1,count,temp);
    return *count;

}
// 非递归，HASH，有点难懂
int numSubarraysWithSum(int* A, int ASize, int S){
    int count = 0,i,sum = 0;
    int temp[ASize+1];
    for(i=0;i<ASize+1;i++){
        temp[i] = 0;
    }
    temp[0] = 1;
    for(i=0;i<ASize;i++){
        sum +=A[i];
        if(sum >= S){
            count += temp[sum-S];
        }
        temp[sum]++;
    }
    return count;

}


// @lc code=end

