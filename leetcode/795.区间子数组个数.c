/*
 * @lc app=leetcode.cn id=795 lang=c
 *
 * [795] 区间子数组个数
 */

// @lc code=start

void recursion(int* A,int ASize,int l,int r,int position,int* count){
    int i,j,max;
    if(position == ASize){
        return;
    }
    max = A[position];
    for(i=position;i<ASize;i++){
        if(max < A[i]){
            max = A[i];
        }
        if(max >= l && max <= r){
            (*count)++;
        }
        if(max > r){
            break;
        }
    }
    recursion(A,ASize,l,r,position+1,count);
}
int numSubarrayBoundedMax(int* A, int ASize, int L, int R){
    // 从头遍历已知数组，对每个元素，求包含它且满足条件的子数组，依次增加计数器，不停递归，知道遍历完数组
    int* count=(int*)malloc(sizeof(int)*1);
    *count = 0;
    recursion(A,ASize,L,R,0,count);
    return *count;
}


// @lc code=end

